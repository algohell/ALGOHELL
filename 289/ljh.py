import copy
class Solution:
    def gameOfLife(self, board):
      board_copy = copy.deepcopy(board)
      col_len = len(board)
      row_len = len(board[0])
      
      for i in range(col_len):
        for j in range(row_len):
          sum_n = self.sum_neighbor(i,j,board)
          # print(sum_n)
          if sum_n == 3:
            board_copy[i][j] = 1
          elif sum_n > 3 or sum_n < 2:
            board_copy[i][j] = 0
      for i in range(col_len):
        for j in range(row_len):
          board[i][j] = board_copy[i][j]

    def sum_neighbor(self,i,j,board):
      count = 0
      for r in range(-1,2):
        for c in range(-1,2):
          try:
            if i+r>=0 and j+c>=0:
              count += board[i+r][j+c]
          except:
            pass
      count -= board[i][j]
      return count
          
  
            
s = Solution()
board = [
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
s.gameOfLife(board)
print(board)