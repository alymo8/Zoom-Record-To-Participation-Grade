#!/bin/bash

#wrong input
if [[ !  $# -eq 2 ]]
then
echo "Usage fixformat.sh <dirname> <opfile>"
exit 1
fi

#if 1st argument is not a valid dir
if [[ ! -d $1 ]]
then
echo "Error $1 is not a valid directory"
exit 1
fi

if [[ -f $2 ]]
then
rm $2
fi
echo "User Email,Name (Original Name),Lab,Total Duration (Minutes)" >> $2

#iterate on files			
for file in $(find $1 -iname 'lab-?.csv'); #semicolon
do

filename=$(basename -- "$file")


#Make lab letter capital
letter=${filename:4:1}
upperc=${letter^}

#change format, 2 cases: if there is 6 fields of 4 fields per line
grep -v Name $file| awk '
BEGIN { FS="," }
{OFS=",";

if(NF == 6) {print $2,$1,lett,$5}; if(NF == 4) {print $2,$1,lett,$3};
}' lett=$upperc >> $2
#pipe to file


done
