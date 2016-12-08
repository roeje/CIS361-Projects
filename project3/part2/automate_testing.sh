#/bin/bash

#Ensure that two arguments have been passed from the user
if [ $# -ne 2 ]
	then
		echo "Missing Arguments"
		echo "Proper Format IS: ./automate_testing.sh [zip file] [destination dir]"
	fi

#get file and dir from parameters
file=$1
dir=$2

#Check if the directory exists, if it does, just extract into existing dir
#if not, make dir and extract into it
if [ -d "$dir" ]
	then
    		unzip $file -d $dir
	else
    		mkdir $dir
    		unzip $file -d $dir
fi

#Save old IFS var
olddelim=$IFS
IFS="_"

#Iterate over all files in dir
#make sub dirs for each username
#Move the files for each username to the user sub dir
for file in "$dir"/*
	do
    		line=$file
    		set $line
    		username=$2
    		filename=${!#}
		#Get the last segment of the file name		
    		echo $filename
    		mkdir -p "$dir/$username"
    		#echo $(pwd)        	
    		mv "$file" "$dir"/"$username"/"$filename"
	done

#Save the old delim back into IFS var
IFS=$olddelim

#Iterate over each user dir
#For each dir, run the makefile in the automate_testing dir
for file in "$dir"/*
do
    if [[ -d $file ]]
    then
	#Move to parent dir and run make file
        make -f ../../makefile -C $file/
        make test -f ../../makefile -C $file/
    fi
done >> report.out 
#Report file saved for all make output
