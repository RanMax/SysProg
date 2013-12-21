#!/bin/bash
echo Script name:$0 
echo Upload folder: $1 
echo Log_file:$2
echo Folder to copy: $3
echo $# arguments entered
echo -------------------
DirName=$1/`date '+%y-%m-%d_%H:%M'`;

#echo $@

 #----------------------------------

if [ -d $DirName ]; then
 echo directory_exists
else
 mkdir $DirName; 
 echo directory $DirName created                
fi
#-----------------------------------

if [ -f $2 ]; then
 echo Log_file_exists
else
 touch $2
 echo Log_file_created          
fi

#------------------------------------
i=3;
until [ $i -gt $# ];do
 echo $i;  
 let i+=1;

 #mv $`i` $DirName;
 #echo $i moved to $DirName; 
 #echo $i moved to $DirName>>$2; #add to log

done #----------------------------------

cd $DirName
if [ -f $3 ]; then
 echo `date '+%y-%m-%d_%H:%M'` $DirName ERROR: Совпадение имени>>$2;
else
         
 #mv $3 .;
 #echo $3 moved to $DirName; 
 echo $3 moved to $DirName>>$2; #add to log
fi

