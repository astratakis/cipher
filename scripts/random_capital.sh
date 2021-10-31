#!/bin/bash



NUMBER=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes 3)
if [ "$NUMBER" == "" ]; then
  NUMBER=0
fi

echo $NUMBER

cat /dev/urandom | tr -dc 'A-Z' | fold -w $NUMBER | head -n 1

NUMBER=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes 3)
if [ "$NUMBER" == "" ]; then
  NUMBER=0
fi

echo $NUMBER

cat /dev/urandom | tr -dc 'A-Z' | fold -w $NUMBER | head -n 1
