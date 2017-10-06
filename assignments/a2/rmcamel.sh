#!/bin/bash

#replace:
#(lowercase character)(uppercase character)

#with:
#(first saved thing)_(second saved thing TOLOWER)

#ie, this:
#myDirtyCamel
#into this:
#my_dirty_camel

for arg in "$@"; do
	sed -i 's|\([a-z]\)\([A-Z]\)|\1_\L\2|g' "$arg"
done
