#!/bin/bash

touch testset_3.txt

echo 10000 > testset_3.txt

for i in {1..10000}
do
    /bin/bash random_capital.sh >> testset_3.txt
done