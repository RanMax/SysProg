#!/bin/bash
echo "Enter the group name"
read groupname
awk -F: '$1 ~ /'$groupname'/ {print $4}' /etc/group > /home/pavel/test.txt #Выводим в файл test.txt через запятую пользователей данно группы
list=`sed -e 's/,/ /g' /home/pavel/test.txt` #редактируем файл для чтения в цикле (удаляем пробелы)
for user in $list
do
sudo adduser $user test_users
echo "In group test_users was added $user"
done
echo"Group $groupname:"
awk -F: '$1 ~ /'test_users'/ {print $4}' /etc/group
echo"End, Bye!"
exit 0
