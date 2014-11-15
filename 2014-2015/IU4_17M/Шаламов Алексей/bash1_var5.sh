#!/bin/bash
$1
$2
backupname=`date "+%Y-%m-%d-%H-%M-%S.tar"`
echo $backupname
echo $1
echo $1
tar -cvzf $backupname $1
mv $backupname $2
