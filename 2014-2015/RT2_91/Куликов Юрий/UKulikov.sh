#!/bin/bash
echo "Please, enter the groupname"
read groupname

awk -F: '$1 ~ /'$groupname'/{print $4}' /etc/group>~/Desktop/result.txt
list=`sed -e 's/,/\n/g' ~/Desktop/result.txt`
for user in $list
do
sudo adduser $user GROUP1
echo "User $user from the group $groupname has been aded to the group:GROUP1"
done
echo "Done"
exit 0
