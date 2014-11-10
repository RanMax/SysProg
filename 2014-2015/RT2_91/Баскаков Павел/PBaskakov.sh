#!/bin/bash
echo "Hello, $USER"
echo "Please, enter the path to the directory" #Вводим название группы, права на которую хотим добавить
read path
echo "Information about $path"
sudo ls -la $path 
echo "Please, enter the group name"
read groupname
sudo chgrp $groupname $path #добавляем права на папку введенной группе
echo "Groupname was successfully changed!"
sudo ls -la $path
exit 0
#Баскаков Павел РТ2-91 Вариант 2 (Раздача прав)
