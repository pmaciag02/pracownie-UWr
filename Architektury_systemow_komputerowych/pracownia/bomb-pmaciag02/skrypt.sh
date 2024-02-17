#!/bin/bash
> brute.txt

test() {
  out=$(./bomb solution.txt <<< "$1 $2 $3 $4 $5 $6")
  echo
}

for ((a=1; a<7; a++))
do
    for ((b=1; b<7; b++))
    do
    	for ((c=1; c<7; c++))
    	do
    	for ((d=1; d<7; d++))
    	do
    	for ((e=1; e<7; e++))
    	do
    	for ((f=1; f<7; f++))
    	do
    
        echo "a: $a b: $b c: $c d: $d e: $e f: $f $(test $a $b $c $d $e $f)" >> brute.txt
        
    done
done
done
done
done
done
