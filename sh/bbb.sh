#!/bin/bash

##########################
# kodi add-ons file sort #
#			 #
##########################
echo "please input file :"

read FILE
echo $FILE
cat $FILE | awk -F ".video." '{print $2}' | tr -s '\n' > tmp1.txt
sort tmp1.txt > tmp2.txt

len=$(cat tmp2.txt | wc -l)
#echo  "len = $len"
for((i=1;i<=len;i++))
do
	cur=$(cat tmp2.txt | sed -n "${i}p")
	echo "plugin.video.$cur" >> new$FILE
done

rm tmp1.txt
rm tmp2.txt
