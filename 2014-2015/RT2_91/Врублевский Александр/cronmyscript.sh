#!/bin/bash
#Directory size script

dir1="$1"
dir2="$2"
calc=$(du -sh "$dir1") 
T=$(date +%H:%M:%S)
D=$(date +%Y-%m-%d)
echo -n "$D" "$T" " |  " >> "$dir2"
echo "$calc" >> "$dir2"
exit 0
