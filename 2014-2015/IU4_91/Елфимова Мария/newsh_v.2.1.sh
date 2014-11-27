#!/bin/bash
if [ "$#" -ne 2 ]; 
then
  echo "Wrong number of arguments ( the correct one is 2 )"
 exit 1
fi
echo $(date +"%Y-%m-%d %H:%M:%S | "$2) >> $1/$(ls $1 | sort -r | head -1)
echo "Log has been updated"
