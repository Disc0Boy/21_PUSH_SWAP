#!/bin/bash

# Generate 5 random numbers between 1 and 100
RANDOM_NUMBERS=$(shuf -i 1-100 -n 5)

# Run the push_swap program with the generated random numbers
./push_swap $RANDOM_NUMBERS
