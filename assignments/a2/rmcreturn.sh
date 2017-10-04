#!/bin/bash

#replace:
#carriage return

#with:
#nothing

for arg in "$@"; do
	sed -i 's|\r||g' "$arg"
done
