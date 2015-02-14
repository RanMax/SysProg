#!/bin/bash
#dir_path = $1
file = "./file.txt"
while read line;
	do 
	mass= ($line)
	done < $file

numelems  = $(#mass[@]);
count = 1
while ["$numelems" - gt 0]
	do 
	mass2 = 'expr match $mass $mass($count)'
	let "count += 1"
done 


echo $word1 = $mass($count);
echo $(mass2(@)#$(mass2($count)

max = 0
count2 = 1
while ["$numelems2" - gt 0]
	do
	if [ $max  /< $mass2($count) ]
	then 
	$max = $mass($count)
	fi
done 


echo $word2= $mass($count2);
echo $(mass2(@)#$(mass2($count2)

max = 0
count3 = 1
while ["$numelems2" - gt 0]
	do
	if [ $max  /< $mass2($count3) ]
	then 
	$max = $mass($count3)
	fi
done 


echo $word1 = $mass($count3);
echo $(mass2(@)#$(mass2($count3)

max = 0
count4 = 1
while ["$numelems2" - gt 0]
	do
	if [ $max  /< $mass2($count4) ]
	then 
	$max = $mass($count4)
	fi
done 


echo $word1 = $mass($count);
echo $(mass2(@)#$(mass2($count)

max = 0
count5 = 1
while ["$numelems2" - gt 0]
	do
	if [ $max  /< $mass2($count5) ]
	then 
	$max = $mass($count5)
	fi
done 
