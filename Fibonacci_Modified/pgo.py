#!/bin/python3

import math
import os
import random
import re
import sys

count = 0

# Complete the fibonacciModified function below.
def fibonacciModified(t1, t2, n):

    global count

    fibo = 0
    
    while count+2 != n:
        fibo = t1 + t2**2
        count = count+1
        
        t1 = t2
        t2 = fibo

    return fibo



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t1T2n = input().split()

    t1 = int(t1T2n[0])

    t2 = int(t1T2n[1])

    n = int(t1T2n[2])

    result = fibonacciModified(t1, t2, n)

    fptr.write(str(result) + '\n')

    fptr.close()
