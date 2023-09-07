#!/bin/bash

if [ "$#" = 3 ];  then 
     if [ "$2" == "$3" ]
 then
      echo "Incorrect input"
    else 
 
	sed -i "" "s/$2/$3/g" $1
  dir=$(pwd)
  size=$(wc -c $1 | awk '{print $1}')
  date=$(date -r $1 "+%Y-%m-%d %H:%M")
  hsh=$(echo -n foobar | shasum -a '256' $1)
  hsh=$(echo ${hsh} | awk '{print $1}')
 
  echo $dir
  echo $size
  echo $date
  echo $hsh

  echo "$1-$size-$date-$hsh-sha256"

  echo "That file was changed"
  echo "$dir-$1-$size-$date-$hsh-sha256" ->>files.log

fi
 else 
   echo "The variables are not three." 
fi
