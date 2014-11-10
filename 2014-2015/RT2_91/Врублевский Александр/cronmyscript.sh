#!/bin/bash
#Directory size script

T=$(date +%H:%M:%S)
D=$(date +%d.%m.%Y)
echo -n "$D" "$T" " |  "
du -hs /home/tols
exit 0
