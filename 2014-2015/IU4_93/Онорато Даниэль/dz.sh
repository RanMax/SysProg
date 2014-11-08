#!/bin/bash
# Scrip que agrega ususarios de archivo

while read line
do
#
	echo $line
	i=1
	for word in $line
	do
		arr[i]=$word
#		echo ${arr[i]}
		let "i +=1"
	done
	if id -u ${arr[1]} >/dev/null 2>&1; then
		echo "User ${arr[1]} exists"
	else
		echo "Created user ${arr[1]} with the password "
		useradd -m ${arr[1]}
		echo ${arr[2]}
	fi
done <$1
