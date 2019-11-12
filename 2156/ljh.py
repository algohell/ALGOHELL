n = int(input())
w_list = [int(input()) for _ in range(n)]

if n<2:
  print(w_list[0])
else:
  dp = [0,w_list[0],w_list[0]+w_list[1]]
  for i in range(3,n+1):
    dp.append(max(dp[i-1],dp[i-2]+w_list[i-1],dp[i-3]+w_list[i-2]+w_list[i-1])) # **0,101,011

  print(dp[-1])