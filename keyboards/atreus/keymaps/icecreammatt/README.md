![cheatsheet](https://user-images.githubusercontent.com/1154569/134296723-f9962d54-75ef-44a1-84c5-5d4d27d3c108.png)
![Screen Shot 2021-09-15 at 9 15 57 PM](https://user-images.githubusercontent.com/1154569/133548509-f391ba86-b150-4560-a098-a4ebb0c64994.png)

# Asahi Linux instructions (Fedora Atreus)
- compile firmware in docker
- flash from host

## Setup

```bash
python3 -m pip install --user qmk
avrdude
```

## Compiling

```bash
$ docker run -it -v (pwd)/:/qmk_firmware:Z  qmk /bin/sh
$ cd ./icecreammatt/
$ ./flash.sh

# or to compile without flashing run
$ qmk compile -kb atreus/astar -km icecreammatt
```

## Flashing
- find device using lsusb

```bash
$ lsusb
$ sudo avrdude -p atmega32u4 -c avr109 -U flash:w:atreus_astar_icecreammatt.hex -P usb:1ffb:0101
```
