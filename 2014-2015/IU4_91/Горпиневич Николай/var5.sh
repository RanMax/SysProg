#!/bin/bash
$dirs
$dirto
backupname=`date "+%Y-%m-%d-%H-%M-%S.tar"`

tar -cvzf $backupname $dirs
mv $backupname $dirto
