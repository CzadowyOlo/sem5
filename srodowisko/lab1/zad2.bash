#!/bin/bash
find "$1" -type f -print0 | xargs -0 cat | sed 's/ \+/\n/g' | sort | uniq -c
# lece po plikach -> na każdym wywoluje polecenie -> rozdzielam tekst białymi znakami -> sortuję -> usuwam i zliczam duplikaty
