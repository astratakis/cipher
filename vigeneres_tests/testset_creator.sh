#!/bin/bash

touch testset_2.txt

echo 1000 > testset_2.txt

for i in {1..1000}
do
    /bin/bash random_capital.sh >> testset_2.txt
done