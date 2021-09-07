#!/bin/bash

qmk c2json -km icecreammatt -kb atreus/astar /Users/matt/qmk_firmware/keyboards/atreus/keymaps/icecreammatt/keymap.c --no-cpp -o layout.json

./replace-keymap-with-numbers.sh


