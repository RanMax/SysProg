echo "vvedite direktoriy logfile"
read dir2
echo "vvedite imia ligfile"
read filename
T=$(date +%H:%M:%S)
D=$(date +%d.%m.%Y)
answer=no
while [ "$answer" = "no" ]; do
echo "vvedite direktoriy file dlia file zapici"
read dir1
du -hs "$dir1"
echo -n "$D" "$T" " |  " >> "$put2"/"$filename"
du -hs "$dir1" >> "$dir2"/"$filename"
echo "da"
read answer
done
exit 0
