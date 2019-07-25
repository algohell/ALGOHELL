#!/usr/bin/env python
# coding: utf-8

# In[ ]:



#240 Search a 2D matrix
# class Solution:
#     def searchMatrix(self, matrix, target):
matrix = [
          [1,   4,  7, 11, 15],
          [2,   5,  8, 12, 19],
          [3,   6,  9, 16, 22],
          [10, 13, 14, 17, 24],
          [18, 21, 23, 26, 30]]
if matrix:
    r = 0
    c = len(matrix)-1
    
    while r < len(matrix) and c >= 0:
        val = matrix[r][c]
        if val == target:
            return True
        
        elif val > target:
            c -= 1
            
        else:
            r += 1
            return False

