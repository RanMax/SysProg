#!/bin/bash
dir=$1
log=$2 

for file in `find $dir -maxdepth 1 -type f`
do 
	login=(`ls -l $file`) 
	login=${login[2]}
	home=""
	while IFS=":" read LOG_NAME LOG_PASSWD LOG_UID LOG_GID LOG_DESC LOG_HOME LOG_SHELL ;
	do  
		if [ $login == $LOG_NAME ];
		then
			home=$LOG_HOME
			break
		fi;
	done < /etc/passwd
	filename=${file##*/} 
	if [ -f "$home/$filename" ]
	then
		echo "$filename already exists in directory $home" >> $log 
	else
		mv "$file" "$home"
	fi;
done;
