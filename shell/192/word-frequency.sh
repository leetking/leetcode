#!/usr/bin/env bash

sed 's/ \+/\n/g' words.txt | sed '/^ *$/d' | sort | uniq -c | sort -r | awk '{print $2, $1}'
