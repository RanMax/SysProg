#!/bin/bash
dir=$1 #пусть до директории, в которой будем искать файлы
log=$2 #путь до лог-файла, в который будем пистаь ошибки

for file in `find $dir -maxdepth 1 -type f`
do 
	login=(`ls -l $file`) #Получает данные по файлу (владелец, группа, права и т.п.)
	login=${login[2]} #Выделяет имя пользователя
	home=""
	while IFS=":" read LOGIN_NAME LOGIN_PASSWD LOGIN_UID LOGIN_GID LOGIN_DESC LOGIN_HOME LOGIN_SHELL ; #Весь цикл нужен для переборки всех пользователей в /etc/passwd и определении каталога данного пользователя
	do  
		if [ $login == $LOGIN_NAME ];
		then
			home=$LOGIN_HOME
			break
		fi;
	done < /etc/passwd
	filename=${file##*/} #получает имя файла из полного пусти
	if [ -f "$home/$filename" ] #проверяет существование файла в домашней директории
	then
		echo "$filename already exists in directory $home" >> $log #Запись в файл лога
	else
		mv "$file" "$home" #перемещение файла в домашний каталог
	fi;
done;
