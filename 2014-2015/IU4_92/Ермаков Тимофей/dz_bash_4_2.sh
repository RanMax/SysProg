#!/bin/bash

if [ "$#" -lt 1 ]; then 
  echo "need filepath to read"  
  exit 1
fi
 
file=$(cat $1);

declare -A wordCounts 

for i in $file; do
    if [ ${wordCounts["$i"]+_} ]; then
	((wordCounts["$i"]++))
    else
	wordCounts["$i"]=1
    fi
done

for k in "${!wordCounts[@]}"
do
    echo $k ' - ' ${wordCounts["$k"]}
done | sort -rn -k3 | head -n5
