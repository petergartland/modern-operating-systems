#!/bin/bash

pwd=$1
cd $pwd
for i in *
	do
	if [ -d $pwd/$i ]; then
		/home/peter/OSbook/chapter4/prob44.bash $pwd/$i
	fi
	if [ -f $pwd/$i ]; then
		echo $pwd/$i
		ls -s $pwd/$i
		#ls -s $pwd/$i | awk '{print $1;}' >> /home/peter/OSbook/chapter4/filesize.txt
	fi
done
