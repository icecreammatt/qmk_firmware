#!/bin/bash

cat layout.json | sed 's/QWERTY/0/g' \
| sed 's/COLEMAK/1/g' \
| sed 's/STANDARD/2/g' \
| sed 's/STDG/3/g' \
| sed 's/NUMERIC/4/g' \
| sed 's/NUM_SPECIAL/5/g' \
| sed 's/POK3R/6/g' > layout-upload.json
