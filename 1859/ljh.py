T = int(input())
anslist = []
for _ in range(T):
  n = int(input())
  sell = list(map(int,input().split()))
  maxval = sell[-1]
  tot = 0
  for i in range(n-2,-1,-1):
    if sell[i]>maxval:
      maxval = sell[i]
    else:
      tot += (maxval-sell[i])
  anslist.append(tot)
  
for t in range(T):
  print("#"+str(t+1),anslist[t])
