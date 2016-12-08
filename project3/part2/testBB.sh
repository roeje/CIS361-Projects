#!/bin/bash

#check to make sure user passed two arguments
if [ $# -ne 2 ]
then
    echo "Error: missing argument(s)"
    echo "Usage: ./bb.sh [zip file] [destination folder]"
fi

#Setting arguements to variables for later user
file=$1
dir=$2

#If passed in directory exists, extract
#If it doesn't exist, make dir and extract
if [ -d "$dir" ]
then
    unzip $file -d $dir
else
    mkdir $dir
    unzip $file -d $dir
fi

#Set field separtor to underscore
old=$IFS
IFS="_"

#Look through all files in extracted directory
#Make folders for each student if neccessary
#Move each students file to their sub-dir
for f in "$dir"/*
do
    line=$f
    set $line
    user=$2
    name=${!#}		
    echo $name
    mkdir -p "$dir/$user"
    #echo $(pwd)
    #echo $f
    echo " "
    #echo "$user/$name"
    #echo " "
    #echo $(ls)	
    mv "$f" "$dir"/"$user"/"$name"
done

#Restore the old field sepator
IFS=$old

#Look through the sub directories for each
#student and run the make scripts
for f in "$dir"/*
do
    if [[ -d $f ]]
    then
        make -f ../../makefile -C $f/
        make test -f ../../makefile -C $f/
    fi
done >> report.txt 
