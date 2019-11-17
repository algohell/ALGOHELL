n,m = map(int,input().split())
order = [tuple(map(int,input().split())) for _ in range(m)]

olist = [[] for _ in range(n+1)]
acclist = [0 for _ in range(n+1)]

for o in order:
  olist[o[0]].append(o[1])
  acclist[o[1]] += 1

res = []
temp = []
for i in range(1,len(acclist)):
    if acclist[i]==0:
      temp.append(i)

while len(res)<n:
  for t in temp:
    temp.remove(t)
    res.append(t)
    for ot in olist[t]:
      acclist[ot] -= 1
      if acclist[ot]==0:
        temp.append(ot)
        
print(' '.join(map(str,res)))
