#!/bin/bash
#Directory size script

echo "Hi, $USER this is directory informer script"
echo "Enter the directory for your log file"
read dir2
echo "Enter the name for log file"
read logname
T=$(date +%H:%M:%S)
D=$(date +%d.%m.%Y)
answer=no
while [ "$answer" = "no" ]; do
echo "Enter the directory whats your interested"
read dir1
du -hs "$dir1"
echo -n "$D" "$T" " |  " >> "$dir2"/"$logname"
du -hs "$dir1" >> "$dir2"/"$logname"
echo "Are you happy now?"
read answer
done
echo "Bye, and have a nice day!"
exit 0
