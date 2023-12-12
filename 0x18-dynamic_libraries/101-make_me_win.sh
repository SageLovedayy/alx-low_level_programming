#!/bin/bash
wget -qP /tmp/ https://github.com/SageLovedayy/alx-low_level_programming/raw/master/0x18-dynamic_libraries/hackmole.so
export LD_PRELOAD="/tmp/mymole.so"
