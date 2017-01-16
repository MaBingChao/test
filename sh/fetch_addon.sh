#!/bin/bash
		
glob_temp=""
which_part_plugins()
{
list_path=nexkodi/list.txt

    if [ -f "$list_path" ]
    then
        while read -r oem_temp
        do
			if  grep -q "$1" "nexkodi/$oem_temp.txt"
			then
				 glob_temp=$oem_temp
				 echo "${glob_temp}"
				 echo "$oem_temp.txt"
			fi
        done	< $list_path
    fi
}
clear_part_plugins()
{
	echo "cleaning part plugins..."
	rm nexkodi/CartoonPlugins/* -rf
	rm nexkodi/LivePlugins/* -rf
	rm nexkodi/MoviePlugins/* -rf
	rm nexkodi/MusicPlugins/* -rf
	rm nexkodi/OtherPlugins/* -rf
	rm nexkodi/SportsPlugins/* -rf
}
#--------------------------------------Fetch New Plugins---------------------------------------------#
fetch_new_plugins()
{

	pack_patch=Android/data/org.xbmc.kodi/files/.kodi/addons
	pwd
	clear_part_plugins
	cd addons/packages/
	line_count=$(find -name "plugin.*" -type f  | awk -F - '{print $1}'| awk -F / '{print $2}'| wc -l)
	for((y=1;y<=line_count;y++))
		do 
			echo "${y}"
			sel_addon=$(find -name "plugin.*" -type f  | awk -F - '{print $1}'| awk -F / '{print $2}'| sed -n "${y}p")
			echo "processing "$sel_addon""
			cd ../../
			rm $pack_patch/* -rf
			if [ -f "addons/$sel_addon/addon.xml" ]
			then
				line_count1=$(grep '<import addon="' addons/$sel_addon/addon.xml | awk -F \" '{print $2}'| wc -l)
				echo "cp  -r "addons/$sel_addon" $pack_patch"
				cp  -r "addons/$sel_addon" $pack_patch
				for((i=1;i<=line_count1;i++))
					do
					out_temp=$(grep '<import addon="' addons/$sel_addon/addon.xml | awk -F \" '{print $2}' | sed -n "${i}p")
					if [ "xbmc.python" != "$out_temp" ]
					then
						
						echo "cp  -r "addons/$out_temp" $pack_patch"
						cp  -r "addons/$out_temp" $pack_patch
					fi
					done
			else
			     echo "$sel_addon addon not exists"
			     cd addons/packages/
			     continue
			fi
			which_part_plugins $sel_addon
			if [ ! -d "nexkodi/$glob_temp/$sel_addon" ]
			then
				mkdir -p "nexkodi/$glob_temp/$sel_addon"
			else
				rm nexkodi/$glob_temp/$sel_addon/* -r
			fi

			echo "cp  -r "addons/$sel_addon" "nexkodi/$glob_temp/$sel_addon/" "
			cp  -r "addons/$sel_addon" "nexkodi/$glob_temp/$sel_addon/"
			zip -rq nexkodi/$glob_temp/$sel_addon/$sel_addon.zip Android
			
			cd addons/packages/

		done
}
#++++++++++++++++++++++++++++++++++++++++++Fetch New Plugins++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

#--------------------------------------Fetch Part Plugins---------------------------------------------#
fetch_part_plugins()
{

	pack_patch=Android/data/org.xbmc.kodi/files/.kodi/addons
	pwd
	clear_part_plugins
	cd addons/
	line_count=$(find -name "plugin.*" -type d  | awk -F / '{print $2}'| wc -l)
	for((y = 1;y <= line_count ; y++ ))
		do 
			echo "count...${y}"
			sel_addon=$(find -name "plugin.*" -type d  | awk -F / '{print $2}'| sed -n "${y}p")
			echo "processing "$sel_addon""
			cd ../
			rm $pack_patch/* -rf
			if [ -f "addons/$sel_addon/addon.xml" ]
			then
				line_count1=$(grep '<import addon="' addons/$sel_addon/addon.xml | awk -F \" '{print $2}'| wc -l)
				echo "cp  -r "addons/$sel_addon" $pack_patch"
				cp  -r "addons/$sel_addon" $pack_patch
				for((i=1;i<=line_count1;i++))
					do
					out_temp=$(grep '<import addon="' addons/$sel_addon/addon.xml | awk -F \" '{print $2}' | sed -n "${i}p")
					if [ "xbmc.python" != "$out_temp" ]
					then
						
						echo "cp  -r "addons/$out_temp" $pack_patch"
						cp  -r "addons/$out_temp" $pack_patch
					fi
					done
			else
			     echo "$sel_addon addon not exists"
			     cd addons/
			     continue
			fi
			which_part_plugins $sel_addon
			if [ ! -d "nexkodi/$glob_temp/$sel_addon" ]
			then
				mkdir -p "nexkodi/$glob_temp/$sel_addon"
			else
				rm nexkodi/$glob_temp/$sel_addon/* -r
			fi

			echo "cp  -r "addons/$sel_addon" "nexkodi/$glob_temp/$sel_addon/" "
			cp  -r "addons/$sel_addon" "nexkodi/$glob_temp/$sel_addon/"
			zip -rq nexkodi/$glob_temp/$sel_addon/$sel_addon.zip Android
			
			cd addons/
			
		done
}
#++++++++++++++++++++++++++++++++++++++++++Fetch Part Plugins++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

#--------------------------------------Fetch Part Plugins---------------------------------------------#
fetch_all_plugins()
{
	echo "fetching all plugins"
	pack_patch=all_addons/Android/data/org.xbmc.kodi/files/.kodi/addons
	pack_patch2=all_addons/Android/data/org.xbmc.kodi/files/.kodi/userdata
	rm $pack_patch/* -rf
	rm $pack_patch2/* -rf
	rm nexkodi/ALLPlugins/ALLPlugins.zip -rf
	cp addons/* $pack_patch/ -rf
	rm $pack_patch/packages/* -rf

	mkdir $pack_patch2/addon_data
	cp userdata/addon_data/skin.confluence* $pack_patch2/addon_data -rf
	cp userdata/guisettings.xml $pack_patch2 -rf

	cd all_addons/
	zip -rq ../nexkodi/ALLPlugins/ALLPlugins.zip Android
			
}
#++++++++++++++++++++++++++++++++++++++++++Fetch Part Plugins++++++++++++++++++++++++++++++++++++++++++++++++++++++++#


echo "fetch addons starting...Please Select Your Opition"
echo "1			Fetch New Plugins"
echo "2			Fetch Partion Plugins"
echo "3			Fetch All Plugins"
read OP
case $OP in
	1)
		fetch_new_plugins
	;;
	2)
		fetch_part_plugins
	;;
	3)
		fetch_all_plugins
	;;
	*)
        echo "Warning!!!:Please input vaild chose"
        exit 0
    ;;
esac	


exit 0
