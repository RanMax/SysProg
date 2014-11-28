#!/bin/bash
directory=$1
log_file=$2

for smth in `ls $directory`
do 
	if [ -f "$directory/$smth" ];
	then
		login=(`stat -c %U "$directory/$smth"`) #Получает им владельца файла
		home=`eval echo ~$login`
		if [ -f "$home/$smth" ] #проверяет существование файла в домашней директории
		then
			echo "$smth already exists in directory $home" >> $log_file #Запись в файл лога
		else	
			mv "$directory/$smth" "$home" #перемещение файла в домашний каталог
		fi;
	fi;
done;
