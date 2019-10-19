N = int(input())
A = list(map(int,input().split()))
oper = list(map(int,input().split()))

def cal(num,n1,n2):
  if num==0:
    return n1+n2
  elif num==1:
    return n1-n2
  elif num==2:
    return n1*n2
  elif num==3:
    if n1<0:
      return -((-n1)//n2)
    else:
      return n1//n2

def findminmax(n,a,op):
  if len(a)==1:
    reslist.append(a[0])
    return
  n1,n2 = a[0],a[1]
  for i in range(4):
    if op[i]!=0:
      op[i]-=1
      if len(a) > 2:
        findminmax(n,[cal(i,n1,n2)]+a[2:],op)
      else:
        findminmax(n,[cal(i,n1,n2)],op)
      op[i]+=1

reslist=[]
findminmax(N,A,oper)

print(max(reslist))
print(min(reslist))