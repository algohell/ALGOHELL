class Solution:
    def uniquePaths(self, m, n):
      if m==0 or n==0:
        return 0
      row_paths = [1 for _ in range(n)]
      for row in range(m-1):
        new_paths=[1]
        for col in range(1,n):
          new_paths.append(new_paths[-1]+row_paths[col])
          print(new_paths)
        row_paths = new_paths
      return row_paths[-1]

s = Solution()
m=7; n=3
print(s.uniquePaths(m,n))