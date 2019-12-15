#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the commonChild function below.
def commonChild(s1, s2):

    # s1_l = list(s1)
    # s2_l = list(s2)
    
    # s1_ll = []
    # s2_ll = []     


    # for i in range(len(s1)):
    #     if s2_l[i] in s1:
    #         s2_ll.append(s2_l[i])
    #     if s1_l[i] in s2:
    #         s1_ll.append(s1_l[i])

    # # print(s2_ll)
    # # print(s1_ll)

    # s2_lll = "".join(s2_ll)
    # s1_lll = "".join(s1_ll)

    # print(s2_lll)
    # print(s1_lll)

    # if not s1_lll:
    #     return 0


    # count1 = 1
    # count2 = 1
    
    # maxc = 0

    # for i in range(len(s1_lll)-1):
    #     for j in range(len(s2_lll)-1):
    #         if s1_lll[i] == s2_lll[j] and s1_lll[i+1] == s2_lll[i+1]: 
    #             count1 += 1
    
    # for i in range(len(s2_lll)-1):
    #     for j in range(len(s1_lll)-1):
    #         if s2_lll[i] == s1_lll[j] and s2_lll[i+1] == s1_lll[i+1]: 
    #             count2 += 1
    
    # if count1 >= count2:
    #     maxc = count1
    # else:
    #     maxc = count2

    # return maxc
    
    # m = len(s1)
    # n = len(s2)

    # C = [[0 for col in range(min(m, n) + 1)] for row in range(2)]
    
    # old_index, new_index = 0, 1

    # for i in range(1, m + 1):
    #     for j in range(1, n + 1):
    #         if s1[i - 1] == s2[j - 1]:
    #             C[new_index][j] = C[old_index][j - 1] + 1
    #         else:
    #             C[new_index][j] = C[new_index][j - 1] if C[new_index][j - 1] >= C[old_index][j] else C[old_index][j]

    #     old_index, new_index = new_index, old_index

    # return C[old_index][n]

 ######################   
    n,m=len(s1),len(s2)
    dp=[[0 for x in range(m+1)] for x in range(n+1)]
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])
            
            if s1[i-1]==s2[j-1]:
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1)
    
    return dp[n][m]

##################
    # memo = [0] * (len(s2) + 1)
    # result  = [0] * (len(s2) + 1)

    # for p in s1:
    #     for i, q in enumerate(s2):
    #         result[i+1] = memo[i] + 1 if p == q \
    #             else max(result[i], memo[i+1])
    #     result, memo = memo, result
    # return memo[-1]



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s1 = input()

    s2 = input()

    result = commonChild(s1, s2)

    fptr.write(str(result) + '\n')

    fptr.close()
