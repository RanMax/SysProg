#!/bin/bash
if [ $# -lt 2 ];
then 
	echo "Not enough parameters!!"
	exit;
fi;
number=$1
filepath=$2

number=$((number+0));
if [ $number -eq 0 ];
then
	echo "Element can't be zero or alphabetical!!"
	exit;
fi;

count=0;
cur_elem=$number;


flag=0;

echo -en "$cur_elem";

while [ $flag -eq 0 ];
do
	flag=1;
	while read line
	do
		line=($line)
		elem=${line[0]}
		parent=${line[1]}
		if [ $elem -eq $cur_elem ];
		then
			flag=0;
			cur_elem=$parent;
			count=$((count+1))
			echo -en "-$cur_elem";
			break;
		fi;
	done < "$filepath"
done;
echo -en "\n";
if [ $count -eq 0 ];
then
	echo "This element doesn't exist in our tree";
else
	count=$((count+1));
	echo "Level of this element is $count";
fi;

echo "This is The End! Happy New Year! Merry Christmas!"
