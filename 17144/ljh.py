import time

start = time.time()

R,C,T = map(int,input().split())
dmap = [list(map(int,input().split())) for _ in range(R)]

dx = [0,1,0,-1]
dy = [1,0,-1,0]

def diffuse():
  temp = [[0 for _ in range(C)] for _ in range(R)]
  for i in range(R):
    for j in range(C):
      if dmap[i][j] >= 0:
        dust = dmap[i][j]//5
        for d in range(4):
          ni,nj = i+dx[d], j+dy[d]
          if 0<=ni<R and 0<=nj<C and dmap[ni][nj]!=-1:
              temp[ni][nj] += dust
              dmap[i][j] -= dust
  for i in range(R):
    for j in range(C):
      dmap[i][j] += temp[i][j]

def cycle():
  global top,bottom
  dmap[top] = [dmap[top][0]] + [0] + dmap[top][1:]
  temp = dmap[top].pop()
  for i in range(top-1,-1,-1):
    temp, dmap[i][-1] = dmap[i][-1], temp
  dmap[0] = dmap[0][:-1] + [temp] + [dmap[0][-1]]
  temp = dmap[0].pop(0)
  for i in range(1,top):
    temp, dmap[i][0] = dmap[i][0], temp
  
  dmap[bottom] = [dmap[bottom][0]] + [0] + dmap[bottom][1:]
  temp = dmap[bottom].pop()
  for i in range(bottom+1,R):
    temp,dmap[i][-1] = dmap[i][-1],temp
  dmap[R-1] = dmap[R-1][:-1] + [temp] + [dmap[R-1][-1]]
  temp = dmap[R-1].pop(0)
  for i in range(R-2,bottom,-1):
    temp,dmap[i][0] = dmap[i][0],temp

top,bottom=-1,-1
for i in range(R):
  for j in range(C):
    if dmap[i][j]==-1:
      if top==-1: top=i
      else: bottom=i

for _ in range(T):
  diffuse()
  cycle()

print(sum(map(sum, dmap))+2)
print("time : ",time.time()-start)