#!/bin/bash

./compile.sh
./gen-layout.sh
./replace-keymap-with-numbers.sh
./flash.sh
