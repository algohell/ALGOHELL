import time
from collections import deque

start = time.time()
N,L,R = map(int,input().split())
pop = [list(map(int,input().split())) for _ in range(N)]

dx=[1,0,-1,0]
dy=[0,1,0,-1]
count = 0

def bfs(x,y):
  visit = set([(x,y)])
  que = deque([(x,y)])
  pnum,unum = 0,0
  while que:
    x,y = que.popleft()
    pnum += pop[x][y]
    unum += 1
    for d in range(4):
      nx,ny = x+dx[d],y+dy[d]
      if 0<=nx<N and 0<=ny<N and (nx,ny) not in visit and (nx,ny) not in totvisit:
        diff = abs(pop[nx][ny] - pop[x][y])
        if L<=diff<=R:
          global check
          check = True
          que.append((nx,ny))
          visit.add((nx,ny))
  return pnum//unum, visit

while True:
  totvisit = set()
  check = False
  union = []

  for i in range(N):
    for j in range(N):
      if (i,j) not in totvisit:
        bfsres,visit = bfs(i,j)
        union.append((bfsres,visit))
        totvisit |= visit
  for (res,uni) in union:
    for u in uni:
      x,y = u
      pop[x][y] = res
  if not check:
    break
  count+=1

print(count)
print("time : ",time.time()-start)