#!/bin/bash

touch testset_1.txt

echo 10 > testset_1.txt

for i in {1..10}
do
    /bin/bash random_alphanumeric.sh >> testset_1.txt
done