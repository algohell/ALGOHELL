anslist = []
T = int(input())
for _ in range(T):
  fee = list(map(int,input().split()))
  use = [0] + list(map(int,input().split()))
  month = [1,1,3]
  ans = fee[3]
  def find_min(m,f):
    global ans
    if m>12:
      if f<ans: ans = f
    else:
      for i in range(3):
        if i==0: find_min(m+month[i],f+(fee[i]*use[m]))
        else: find_min(m+month[i],f+fee[i])
  find_min(1,0)
  anslist.append(ans)
for t in range(1,T+1):
  print("#"+str(t),anslist[t-1])