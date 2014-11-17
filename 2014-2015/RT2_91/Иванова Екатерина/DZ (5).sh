#!/bin/bash
#Задание №5

echo "Enter the path to the archived directory"

read path #Считываем путь до архивируемой директории

echo "Enter the path in which you want to place the created archive"

read dirpath #Считываем путь директории, в которую необходимо поместить архив

D=$(date +%F_%H-%M-%S)

echo "Created archive $D.tar.gz in directory $dirpath"

tar czvf $D.tar $path #Создаем архив

sudo mv  $D.tar $dirpath #Перемещаем архив

exit 0
