#!/bin/bash
echo sestina e martingala strategy
for filename in ./serie/*.txt; do
        ./build/roulette "$filename" 
done
echo nassa e contro
for filename in ./serie/*.txt; do
        ./build/nassa_e_contro "$filename" 
done