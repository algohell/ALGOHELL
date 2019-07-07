class Solution(object):
  def setZeroes(self, matrix):
    if not matrix or not matrix[0]:
      return 0

    rows = len(matrix)
    cols = len(matrix[0])
    first_row_zero = any([True for c in range(cols) if matrix[0][c] == 0])
    first_col_zero = any([True for r in range(rows) if matrix[r][0] == 0])
    #print(first_row_zero)
    #print(first_col_zero)

    for r in range(1, rows):
      for c in range(1, cols):
       #print("1",r,c)
        if matrix[r][c] == 0:
          matrix[r][0] = 0
          matrix[0][c] = 0
    #print(matrix)

    for r in range(1, rows):
      if matrix[r][0] == 0:
        for c in range(1, cols):
          #print("2",r,c)
          matrix[r][c] = 0
    #print(matrix)

    for c in range(1, cols):
      if matrix[0][c] == 0:
        for r in range(1, rows):
          #print("3",r,c)
          matrix[r][c] = 0
    #print(matrix)

    if first_row_zero:
      matrix[0] = [0] * cols
    if first_col_zero:
      for r in range(rows):
        matrix[r][0] = 0

s = Solution()
matrix=[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
s.setZeroes(matrix)
print(matrix)