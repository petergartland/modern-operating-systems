#!/bin/bash
pwd=$1
cd $pwd
for i in *
	do
	if [ -d $pwd/$i ]; then
		/home/peter/OSbook/chapter4/prob45.sh $pwd/$i
	fi
	if [ -f $pwd/$i ]; then
		echo $pwd/$i
		#ls -i $pwd/$i
		ls -i $pwd/$i
		ls -i $pwd/$i >> /home/peter/OSbook/chapter4/inodes.txt
	fi
done
