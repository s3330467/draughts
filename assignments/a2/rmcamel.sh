#!/bin/bash

#replace:
#(lowercase character)(uppercase character)

#with:
#(first saved thing)_(second saved thing TOLOWER)

for arg in "$@"; do
	sed -i 's|\([a-z]\)\([A-Z]\)|\1_\L\2|g' "$arg"
done
