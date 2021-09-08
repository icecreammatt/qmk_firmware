#!/bin/bash

cat layout.json | sed 's/QWERTY_PLN/2/g' \
| sed 's/COLEMAK_PLN/3/g' \
| sed 's/QWERTY/0/g' \
| sed 's/COLEMAK/1/g' \
| sed 's/NUMERIC/4/g' \
| sed 's/NUM_SPECIAL/5/g' \
| sed 's/SPECIAL/6/g' \
| sed 's/POK3R/7/g' \
| sed 's/FKEYS/8/g' \
| sed 's/WINDOW/9/g' \
| sed 's/MOUSE/10/g' \
| sed 's/BLANK_11/11/g' \
| sed 's/BLANK_12/12/g' \
| sed 's/GAMING/13/g' \
| sed 's/PROGRAM/14/g' \
| sed 's/MODE_SWITCH/15/g' > layout-upload.json
