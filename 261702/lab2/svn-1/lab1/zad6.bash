#!/bin/bash

# generate list of duplicated words in suplied dir. Newline is separator
duplist() {
    find "$1" -type f -print0 | xargs -0 cat | sed 's/ \+/\n/g' | sort | uniq -d
}

tmpfile=$(mktemp) # buffer for deferring grep output
trap 'rm -f $tmpfile' 0 2 3 15

duplist "$1" | while read -r word || [[ -n $word ]];
do
    if grep -E "(^| )$word( .* | )$word( |$)" -rn "$1" > tmpfile; then
        printf '%s:\n' "$word"; cat tmpfile
    fi
done
