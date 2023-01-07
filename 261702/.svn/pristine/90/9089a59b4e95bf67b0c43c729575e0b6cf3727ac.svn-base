#!/bin/bash
find "$1" -type f -print0 | xargs -0 cat | sed 's/ \+/\n/g' | sort | uniq -c
