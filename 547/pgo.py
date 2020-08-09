class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        N = len(M)

        seem = set()


class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:

        def dfs(M, cur, n):
            for i in range(n):
                if M[cur][i] == 1:
                    M[cur][i] = M[i][cur] = 0
                    dfs(M, i, n)

        l_m = len(M)
        ans = 0

        for i in range(l_m):
            # print(i)
            if M[i][i] == 1:
                ans += 1
                dfs(M, i, l_m)

        return ans