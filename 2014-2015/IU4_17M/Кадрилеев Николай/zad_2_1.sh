I#!/bin/bash
dir_name=$1
text=$2
if [ $# -lt 2 ];
then
	echo "Not enough parameters!!!"
	exit 1;
fi;
for file in `find $1 -maxdepth 1 -regextype posix-basic -regex "$1/Log[0-9]\{1,\}"  -type f | sort`
do
	tmp=1 #Useless cycle to receive last element  Massive already sorted
done
time=`date '+%Y-%m-%d %H:%M:%S'`
echo "$time | $text">>$file
