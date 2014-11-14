#!/bin/bash
FILE=$1
while read line;
do
	mass=($line)
	user="${mass[0]}"
	passw="${mass[1]}"
	pass=$(perl -e 'print crypt($ARGV[0], "password")' $passw)
	grep $user":" /etc/passwd>/dev/null
	if [ $? -ne 0 ]; 
	then
		useradd -p "$pass" "$user"
		echo "$user created!"
	else 
		echo "$user already exists in the system"
	fi
done < $FILE
