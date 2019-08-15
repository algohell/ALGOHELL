import collections
class Solution:
    def shortestBridge(self, A):
      row, col = len(A), len(A[0])
      di = [(1,0),(-1,0),(0,1),(0,-1)]
      visit = [[0 for _ in range(col)] for _ in range(row)]
      check = False
      q = collections.deque()
      for i in range(row):
        if check: break
        for j in range(col):
          if A[i][j] == 1:
            self.dfs(A,i,j,visit,q)
            check = True
            break
      count = 0
      while q:
        size = len(q)
        for _ in range(size):
          i,j = q.popleft()
          for d in di:
            a, b = i + d[0], j + d[1]
            if 0 <= a < row and 0 <= b < col:
              visit[a][b] = 1
              if A[a][b] == 1:
                return count
              elif A[a][b] == 0:
                A[a][b] = 2
                q.append((a,b))
              else:
                continue
        count += 1
      return count
    def dfs(self,A,i,j,visit,q):
      if visit[i][j]: return
      visit[i][j] = 1
      row, col = len(A), len(A[0])
      di = [(1,0),(-1,0),(0,1),(0,-1)]
      if A[i][j] == 1:
        q.append((i,j))
        A[i][j] = 2
        for d in di:
          a, b = i + d[0], j + d[1]
          if 0 <= a < row and 0 <= b < col:
            self.dfs(A,a,b,visit,q)


s = Solution()
# A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
A = [[1,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,1]]
# A = [[0,1,0],[0,0,0],[0,0,1]]
# A = [[1,0],[0,1]]
c = s.shortestBridge(A)
print(A)
print(c)
