#! /bin/bash
while read f
do
	if test -f $f
		then
			echo $f
	fi		
done
