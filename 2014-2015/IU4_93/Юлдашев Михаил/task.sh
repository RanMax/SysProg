#!/bin/bash
n_elem=$#
if [ $n_elem -lt 1 ];
then
	echo "Not enough arguments: $n_elem"
	exit 1
 else
 	
 	group=$1
 	while read line; do
 		name=`echo $line | cut -d : -f 1`
 		grp=`groups $name`
 		grp=${grp#*:}
 		for xgroup in $grp; do
 			if [ "$xgroup" = "$group" ] 
 			then
 				gpasswd -a $name test;
 			fi
 		done
 	done < /etc/passwd
fi
echo "The task is complete!!! Congratulations!!!)))"
exit 0
