#!/bin/bash
dir_path=$1
log_path=$2
bytes=(`du -s $dir_path`)
bytes=${bytes[0]} 
size=''
if [ $bytes -ge 1073741824 ];
then
	size=$(($bytes/1073741824))'G'
elif [ $bytes -ge 1048576 ];
then
	size=$(($bytes/1048576))'M'
elif [ $bytes -ge 1024 ];
then
	size=$(($bytes/(1024)))'K'
else
	size=$bytes
fi;
time=`date '+%Y-%m-%d %I:%M %P'`
echo "$time | $size" >> $log_path
