#!/bin/bash

EXE=./huffman
N=100
FAIL=0
FAIL_LOG=()

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

printf "Huffman Stress Test: %d random strings\n" "$N"
for i in $(seq 1 $N); do
    # Generate a random string of length 1-200 with printable ASCII
    LEN=$((RANDOM % 200 + 1))
    STR=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9 .,:;!?@#%&*()[]{}' | head -c $LEN)
    # Run the program and capture output
    OUT=$($EXE "$STR")
    DECODED=$(echo "$OUT" | grep '^Decoded:' | sed 's/Decoded: //')
    if [ "$STR" != "$DECODED" ]; then
        echo -e "${RED}[$i/$N] FAIL${NC}: input='$STR' decoded='$DECODED'"
        FAIL=$((FAIL+1))
        if [ ${#FAIL_LOG[@]} -lt 5 ]; then
            FAIL_LOG+=("Input: $STR\nDecoded: $DECODED\n")
        fi
    else
        echo -ne "${GREEN}[$i/$N] PASS${NC}\r"
    fi
    # Progress bar
    if (( i % 10 == 0 )); then
        echo -ne "Tested $i/$N\r"
    fi
    sleep 0.01
    # Remove carriage return for last test
    if [ "$i" -eq "$N" ]; then echo; fi
    done

if [ $FAIL -eq 0 ]; then
    echo -e "${GREEN}All $N tests passed!${NC}"
else
    echo -e "${RED}$FAIL/$N tests failed.${NC}"
    echo "--- First few failed cases ---"
    for log in "${FAIL_LOG[@]}"; do
        echo -e "$log"
    done
fi