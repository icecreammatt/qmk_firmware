#!/bin/bash

cat layout.json | sed 's/_QW/0/g' \
| sed 's/COLEMAK/1/g' \
| sed 's/NUMERIC/2/g' \
| sed 's/NUM_SPECIAL/3/g' \
| sed 's/SPECIAL/4/g' \
| sed 's/WINDOW/5/g' \
| sed 's/POK3R/7/g' \
| sed 's/MOUSE/8/g' \
| sed 's/FKEYS/10/g' \
| sed 's/GAMING/13/g' \
| sed 's/PROGRAM/14/g' \
| sed 's/MODE_SWITCH/15/g' > layout-upload.json
