#!/bin/bash

# Program arguments:
#	$1 must be a positive integer
#	$2 must be a number in [1, 3]
#	$3 must be a positive integer
#	$4 must be a string with a .txt file extension

if [[ $# -ne 4 ]]
then
	echo "Usage: $0 <T> <Alg> <N> <F>"
	echo "OPTIONS:"
	echo "	<T>:		The number of test cases."
	echo "	<Alg>:		The algorithm choice."
	echo "		1:	OTP."
	echo "		2:	Caesar's."
	echo "		3:	Vigenere's."
	echo "	<N>:		The maximum string length."
	echo "	<F>: 		The output file name."
	
	echo
	echo "Example: $0 100 3 100 testset_1.txt"
	echo "This will create 100 test cases for Vigenere's algorithm with maximum string length 100 and the test file will be named testset_1.txt"
	exit 1
fi

number_format='^[0-9]+$'
letter_format='[a-zA-Z]'

if ! [[ $1 =~ $number_format ]] || [[ $1 -lt 1 ]]
then
	echo "[ERROR]: Expected positive integer <T>"
	exit 1
fi

if ! [[ $2 =~ $number_format ]] || [[ $2 -lt 1 ]] || [[ $2 -gt 3 ]]
then
	echo "[ERROR]: Expected integer <Alg> in range: [1, 3] inclusive"
	exit 1
fi

if ! [[ $3 =~ $number_format ]] || [[ $3 -lt 1 ]]
then
	echo "[ERROR]: Expected positive integer <N>"
	exit 1
fi

if ! [[ $4 =~ $letter_format ]]
then
	echo "[ERROR]: Expected string <F>"
fi

# Starting the process of test creation

touch $4

echo $1 > $4

for ((i=1; i<=$1; i++));
do
	if [[ $2 -eq 1 ]]
	then
		echo asdf
		# OTP random testset
	elif [[ $2 -eq 2 ]]
	then
		echo asdf
		# Caesar's random testset
	else
		# Vigenere's random testset
		/bin/bash random_capital.sh $3 >> $4	# Input string
		/bin/bash random_capital.sh $3 >> $4	# Key
	fi	
done

