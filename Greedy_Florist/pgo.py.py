#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the getMinimumCost function below.
def getMinimumCost(k, c):

    c = sorted(c, reverse=True)
    #print(c)

    cost = 0
    p_purchase = 0
    
    for i in range(n):
        cost += (p_purchase + 1) * c[i]
        if (i+1) % k == 0 and (i+1) // k > 0:
            p_purchase += 1
    dis
    return cost


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    minimumCost = getMinimumCost(k, c)

    fptr.write(str(minimumCost) + '\n')

    fptr.close()
