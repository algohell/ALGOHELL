# 120.triangle
#triangle = [[2], [3,4], [6,5,7], [4,1,8,3]]
triangle = [[-1], [2,3], [1,-1,-3]]
t = triangle
tl = len(t)
dp = t[-1]
print(dp)

for i in range(tl-2, -1, -1):
    for j in range(i+1):
        dp[i] = min(dp[j], dp[j+1]) + t[i][j]

print(dp[0])