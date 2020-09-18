#!/bin/bash

#while read line; do
#echo $line
#done < test2

exec 3> test2
for i in {1..100}; do
	flock 3
	last_line=$(tail -n1 test2)
	let last_line=last_line+1
	echo $last_line >> test2
	echo $$
	flock -u 3
done
