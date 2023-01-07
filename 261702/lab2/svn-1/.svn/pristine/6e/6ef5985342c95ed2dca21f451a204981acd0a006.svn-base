#!/bin/bash
find "$1" -type f -exec \
    sh -c 'sed "s/ \+/\n/g" "$1" | sort | uniq' sh {} \; | # dedup individual files
    sort | uniq -c # count dups in concatenation of deduped files
