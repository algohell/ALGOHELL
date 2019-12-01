nk = input().split()
n = int(nk[0])
k = int(nk[1])
c = list(map(int, input().rstrip().split()))
    
    
csort = sorted(c,reverse=True)
res,count,temp = 0,1,k

for f in csort:
    if temp==0: 
        temp=k
        count+=1
    res += count*f
    temp-=1
print(res)