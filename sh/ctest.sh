
#!/bin/bash

glob_temp=""
list_path=/home/blue/sh_test/txt/list.txt
list_patha=/home/blue/sh_test/txt
    if [ -f "$list_path" ]
    then
	echo "1111111"
        while read -r oem_temp
        do
		if grep -q "$1" "txt/$oem_temp.txt"
		then
		pwd
		echo "${oem_temp}"
				 glob_temp=$oem_temp
				 echo "$glob_temp.txt"
		fi
        done	< $list_path
    fi


no1(){
if [ -f $list_path ]
then
	while read -r oem_temp
	do
		echo "${oem_temp}"
	done <$list_path

fi
}

no(){
add_path=/home/blue/sh_test
package_tmp=/home/blue/sh_test/package


line_count=$(find -name "plugin.*" -type d | awk -F / '{print $2}' | wc -l)

echo "line_count = $line_count "

for((y=1;y<=${line_count};y++))
 do
	echo "$y"
	sel_addon=$(find -name "plugin.*" -type d | awk -F / '{print $2}' | sed -n "${y}"p)
	echo "$sel_addon "
	cd ${sel_addon}
	pwd
	if [ -f addon.xml ]
	then
		lib_number=$(grep '<import addon="' addon.xml | awk -F / '{print $1}' | wc -l)
		echo "$lib_number "
		for((i=1;i<=${lib_number};i++))
		do
			lib_char=$(grep '<import addon="' addon.xml | awk -F \" '{print $2}' | sed -n "${i}"p)
			if [ "$lib_char" != "xbmc.python" ]
			then
				cp -rf ../$lib_char ${package_tmp}
			fi
		done
	fi
	which_part $sel_addon

	cd ../
 done
}
