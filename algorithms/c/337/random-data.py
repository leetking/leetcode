#!/usr/bin/env python

import json
from random import randint
n = int(input("How many data?"))
print(json.dumps(([randint(1, n/2) for _ in range(n)])))
