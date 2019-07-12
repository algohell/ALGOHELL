from bisect import bisect_left
class Solution:
  def searchMatrix(self, matrix, target):
    if not matrix:
      return False
      
    sum_mat = sum(matrix,[])
    sorted_mat = sorted(sum_mat)
    res = bisect_left(sorted_mat,target)

    if res != len(sorted_mat) and sorted_mat[res] == target:
      return True
    else:
      return False

matrix = [
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24], 
  [18, 21, 23, 26, 30]
]
target = 5
s = Solution()
print(s.searchMatrix(matrix,target))