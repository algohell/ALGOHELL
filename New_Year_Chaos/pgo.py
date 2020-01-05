New Year Chaos

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
    # moves = 0

    # r = [i-1 for i in q]

    # #print(r)

    # for i,v in enumerate(r):
    #     #print(i,v)

    #     if v - i > 2:
    #         print("Too chaotic")
    #         return

    #     for j in range(max(v-1,0), i):
    #         if r[j] > v:
    #             moves += 1
    
    # print(moves)

##########################

    # bribes = 0

    # for i in range(len(q)-1, -1, -1):
    #     if q[i] - (i+1) > 2:
    #         print('Too chaotic')
    #         return
        
    #     for j in range(max(0, q[i]-2), i):
    #         if q[j] > q[i]:
    #             bribes += 1

###########################

    l_index = len(q)-1

    numOfswaps = 0

    is_swaped = False

    for i,v in enumerate(q):
        if v-1-i > 2:
            print('Too chaotic')
            return

    #bubble sort
    for i in range(0, l_index):
        for j in range(0, l_index):
            if q[j] > q[j+1]:
                q[j], q[j+1] = q[j+1], q[j]
                numOfswaps += 1
                is_swaped = True

        if is_swaped:
            is_swaped = False
        else:
            break
    print(numOfswaps)            

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
