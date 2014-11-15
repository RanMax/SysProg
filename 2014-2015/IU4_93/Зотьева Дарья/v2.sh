#!/bin/bash
tar_group=$1
src_group='group1'
users=''
id_grp=''
while IFS=":" read GROUP_NAME GROUP_PASS GROUP_ID GROUP_LIST #Весь цикл нужен для переборки всех групп в /etc/group
	do  
		if [ $src_group == $GROUP_NAME ];
		then
			users=$GROUP_LIST
			id_grp=$GROUP_ID
			break
		fi;
	done < /etc/group
while IFS=":" read LOGIN_NAME LOGIN_PASSWD LOGIN_UID LOGIN_GID LOGIN_DESC LOGIN_HOME LOGIN_SHELL ; #Весь цикл нужен для переборки всех пользователей в /etc/passwd
	do  
		if [ $id_grp == $LOGIN_GID ] && [ "$users" != '' ];
		then
			users=$users",$LOGIN_NAME"
			break
		elif [ $id_grp == $LOGIN_GID ] && [ "$users" == '' ];
		then
			users=$LOGIN_NAME
			break
		fi;
	done < /etc/passwd

for user in $(echo $users | tr "," "\n")
do
	usermod -a -G "$tar_group" "$user"
done
