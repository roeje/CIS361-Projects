# /bin/bash
while read file
do
	set $file
	echo $1
done < classes.txt
