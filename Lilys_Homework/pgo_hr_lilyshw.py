#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the lilysHomework function below.
def lilysHomework(arr):

    arr_d1 = dict(zip(arr, range(len(arr))))
    arr_d2 = arr_d1.copy()

    c1 = 0
    c2 = 0

    sorted_arr = sorted(arr)
    sorted_arr_r = sorted(arr, reverse = True)


    for a in range(len(arr)):
        if(arr_d1[sorted_arr[a]] != a):
            c1 += 1
            arr_d1[sorted_arr[a]], arr_d1[arr[a]] = \
                   a, arr_d1[sorted_arr[a]]
            
    for r in range(len(arr)):
        if(arr_d2[sorted_arr_r[r]] != r):
            c2 += 1
            arr_d2[sorted_arr_r[r]], arr_d2[arr[r]] = \
                   r, arr_d2[sorted_arr_r[r]]

    ans = min(c1, c2)

    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = lilysHomework(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
