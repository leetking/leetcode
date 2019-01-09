#!/usr/bin/env bash

# format: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

# TODO use extend grep (grep -E)
grep '^\([0-9]\{3\}-\|([0-9]\{3\}) \)[0-9]\{3\}-[0-9]\{4\}$' file.txt

