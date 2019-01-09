#!/usr/bin/env bash

sed -n '10p' file.txt

# other solution
# 1. awk 'NR == 10' file.txt
