from collections import Counter 

t = int(input())
reslist = []
for _ in range(t):
    n = input()
    num = [s for s in n]
    cnt = Counter(num)
    ans = 0
    for k,v in cnt.items():
        if v%2==1: 
          ans+=1
    reslist.append(ans)

for i in range(1,t+1):
    print("#"+str(i),reslist[i-1])
