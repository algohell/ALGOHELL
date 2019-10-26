n = int(input())

dp = [0] + [1,2,3] + [0 for _ in range(n-3)]

def find_case(n):
  if n<4: return dp[n]
  for i in range(4,n+1):
    dp[i] = dp[i-1]+dp[i-2]
  return dp[n]

print(find_case(n)%10007)

