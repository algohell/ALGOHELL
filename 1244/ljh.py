import copy

def find_max(nlist,start,swap):
  global ans
  if swap==0:
    string = ''.join(nlist)
    if ans<int(string):
      ans = int(string)
    return
  if start==len(nlist):
    if swap%2==0:
      string = ''.join(nlist)
      if ans<int(string):
        ans = int(string)
      return
    else:
      anstemp=0
      for i in range(1,len(nlist)):
        cp = copy.deepcopy(nlist)
        cp[i-1],cp[i] = cp[i],cp[i-1]
        cpint = int(''.join(cp))
        if anstemp<cpint:
          anstemp=cpint
      ans = anstemp
      return
  maxval = max(nlist[start:])
  temp=[]
  for i in range(start,len(nlist)):
    if maxval==nlist[i]:
      temp.append(i)
  for t in temp:
    cp = copy.deepcopy(nlist)
    if cp[start]!=cp[t]:
      cp[start],cp[t] = cp[t],cp[start]
      find_max(cp,start+1,swap-1)
    else:
      find_max(cp,start+1,swap)

anslist = []
T = int(input())
for _ in range(T):
  n,swap = map(int,input().split())
  n = [s for s in str(n)]
  ans = -1 
  find_max(n,0,swap)
  anslist.append(ans)
for i in range(1,T+1):
  print("#"+str(i),anslist[i-1])