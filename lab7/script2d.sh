# /bin/bash
while read file
do
	set $file
	echo $1
	mkdir -p $1
	touch $1/$2	
done < classes.txt
