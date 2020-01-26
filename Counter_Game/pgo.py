#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the counterGame function below.
def counterGame(n):

    n = n - 1

    bin_n = bin(n)[2:]

    bin_n_c = bin_n.count('1')

    print(bin_n_c)

    if bin_n_c % 2 == 0:
        return "Richard"

    else:
        return "Louise"

###################################

    # bin_n = bin(n)

    # count1 = 0
    # count0 = 0

    # for i in range(len(bin_n)-1, 1, -1):
    #     if bin_n[i] == '1':
    #         #print(bin_n[i])
    #         count1 += 1
    #         #print("Count1:", count1)
    #     elif count1 == 0:
    #         count0 += 1
    #         #print("Count0:", count0)

    # countT = count1 + count0

    # if countT % 2 == 0:
    #     return "Louise"

    # else:
    #     return "Richard"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = counterGame(n)

        fptr.write(result + '\n')

    fptr.close()
