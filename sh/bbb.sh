#!/bin/bash

len=$(cat 3.txt | wc -l)

echo  "len = $len"

for((i=1;i<=len;i++))
do
	cur=$(cat 3.txt | sed -n "${i}p")
	echo "plugin.video.$cur"
done
