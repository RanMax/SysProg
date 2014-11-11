#!/bin/bash
echo "Введите архивируемый каталог:"
read userdir
echo "Выберите каталог для хранения:"
read backupdir
backupname=`date "+%Y-%m-%d-%H-%M-%S.tar"`
echo $backupname
#backupname1=aaa

tar -cvzf $backupname $userdir
mv $backupname $backupdir
