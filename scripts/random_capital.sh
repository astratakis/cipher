#!/bin/bash

NUMBER=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $1)
if [ "$NUMBER" == "" ]; then
  NUMBER=0
fi

if [[ $NUMBER -eq 0 ]]
then
	echo "ERROR"
	exit 1
fi

echo $NUMBER

cat /dev/urandom | tr -dc 'A-Z' | fold -w $NUMBER | head -n 1
