#!/bin/python3

import math
import os
import random
import re
import sys


def arrangeRanking(li, rank):
    rank[0] = 1
    for index, element in enumerate(li):
        if index > 0:
            if element == li[index - 1]:
                rank[index] = rank[index - 1]
            else:
                rank[index] = rank[index - 1] + 1

def findScore(li, target, begin, end):
    mid = (int)((begin + end)/2)
    if li[mid] < target:
        end = mid
        if end < 0:
            end = 0
    elif li[mid] > target:
        begin = mid
    else: # if same
        return mid

    if (end - begin) == 1:
        if li[end] < target:
            if li[begin] < target:
                return begin
            return end
        else:
            return end + 1
    return findScore(li, target, begin, end)


# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    
    # l = []
    # ans = []

    # for a in alice:

    #     index = 0

    #     scores.append(a)

    #     scores_l = sorted(list(set(scores)), reverse = True)

    #     scores_d = dict(zip(range(len(scores_l)), scores_l))

    #     l.append([r for r,s in scores_d.items() if s == a])

    #     print(l)

    # for i in l:
    #      ans.append(int(*i)+1)

    # return ans

    ranking = scores[:]

    arrangeRanking(scores, ranking)

    print(scores)
    print("ranking", ranking)
    result = []
    for element in alice:
        tmp = findScore(scores, element, 0, len(scores) - 1)
        if tmp >= len(scores):
            result.append(ranking[tmp-1] + 1)
        else:
            result.append(ranking[tmp])
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()