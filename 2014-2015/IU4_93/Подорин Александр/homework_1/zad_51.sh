#!/bin/bash
if [ $# -lt 2 ];
then
	echo "Not enough parameters"
	exit 1
fi;
dir_path=$1
search_string=$2
if [ ! -d "$dir_path" ];
then
	echo "Directory not exist"
	exit 2
fi;

for file in `find "$dir_path" -maxdepth 1 -type f`
do
	line_num=0
	while read line ;
	do
		line_num=$(( $line_num+1 ))
		if [[ "$line" == *"$search_string"* ]]; 
		then
			filename=${file##*/}
			echo "$filename:$line_num $line"
		fi;
	done < $file
done;
