#!/bin/bash

# generate list of words in dir. Newline is used as separator
wordlist() {
    find "$1" -type f -print0 | xargs -0 cat | sed 's/ \+/\n/g' | sort | uniq
}

wordlist "$1" | while read -r word || [[ -n $word ]];
do
    printf '%s:\n' "$word"
    grep -E "(^| )$word( |$)" -rn "$1" 
done
