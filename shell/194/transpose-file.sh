#!/usr/bin/env bash

transpose-file() {
    local array=()
    local width=0
    local height=0
    for ((h = 0; ; h++)); do
        read -r -a line
        if [ 0 -eq ${#line[@]} ]; then
            break
        fi
        width=${#line[@]}
        height=$((height+1))
        for ((w = 0; w < width; w++)); do
            array[$((h*width+w))]=${line[$w]}
        done
    done
    for ((w = 0; w < width; w++)); do
        for ((h = 0; h < height; h++)); do
            echo -n "${array[$((h*width+w))]}"
            # newline
            if [ $((h+1)) -eq $height ] ; then
                echo ""
            # just a space
            else
                echo -n " "
            fi
        done
    done
}

transpose-file < file.txt
