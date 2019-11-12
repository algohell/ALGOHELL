n = int(input())
dp = [0] + ([1] * 9)

for i in range(1,n):
  temp = [0 for _ in range(10)] 
  for j in range(10):
    if j==0:
      temp[j] = dp[1]
    elif j==9:
      temp[j] = dp[8]
    else:
      temp[j] = dp[j-1] + dp[j+1]
  dp = temp

print(sum(dp))
    