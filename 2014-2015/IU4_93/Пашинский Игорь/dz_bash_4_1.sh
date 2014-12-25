#!/bin/bash
if ((BASH_VERSINFO[0] < 4));
then
	echo "Need Bash version bigger then 4";
	exit;
fi;
if [ $# -lt 1 ]
then
	echo "Not enough parameters!!";
	exit;
fi;

max_elem_num=5;

declare -A words

while read line;
do
	for word in $line;
	do
		words[$word]=$((words[$word]+1))
	done;
done < $1


echo "Top of the top";
while [ $max_elem_num -gt 0 ];
do
	cur_max_name='';
	cur_max_count=0;
	for k in "${!words[@]}";
	do
		if [ $((words[$k])) -gt $cur_max_count ];
		then
			cur_max_count=$((words[$k]));
			cur_max_name=$k;
		fi;
	done;
	
	unset words[$cur_max_name];
	echo "$cur_max_name-$cur_max_count";
	max_elem_num=$((max_elem_num-1));
done;
