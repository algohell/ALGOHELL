class Solution:
    def minimumTotal(self, triangle):
        # idx = 0
        # ans = triangle[0][0]
        # i = 1
        # def rec(tri,i,idx,ans): # recursion. time limit exceeded
        #     if i == len(tri): return ans
        #     return min(rec(tri,i+1,idx,ans+tri[i][idx]),rec(tri,i+1,idx+1,ans+tri[i][idx+1]))
        
        for i in range(len(triangle)-2,-1,-1): # 뒤집어서 하나씩 참조
            for j in range(len(triangle[i])):
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1])
        return triangle[0][0]
s = Solution()
triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
s.minimumTotal(triangle)
