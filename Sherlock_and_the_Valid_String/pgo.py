#!/bin/python3

import math
import os
import random
import re
import sys

from collections import Counter

# Complete the isValid function below.

def isValid(s):

    s_v = sorted(list(Counter(s).values()))
    
    #print(s_v)

    if s_v.count(s_v[0]) == len(s_v) or (s_v.count(s_v[0]) == len(s_v) - 1 and s_v[-1] - s_v[-2] == 1) or  (s_v.count(s_v[-1]) == len(s_v) - 1 and s_v[0] == 1):
        return "YES"

    else:
        return "NO"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
