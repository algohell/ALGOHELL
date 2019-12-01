from collections import defaultdict

maxcnt = -1
def dfs(i,j,cnt):
    global maxcnt
    for d in range(4):
        if -1<i+dx[d]<n and -1<j+dy[d]<n:
            if vis[i+dx[d]][j+dy[d]]!=1 and rooms[i+dx[d]][j+dy[d]]-rooms[i][j]==1:
                vis[i+dx[d]][j+dy[d]] = 1
                dfs(i+dx[d],j+dy[d],cnt+1)
    vis[i][j] = 0
    if maxcnt<cnt: maxcnt = cnt
    return

t = int(input())
reslist = []
for _ in range(t):
    n = int(input())
    rooms = [list(map(int,input().split())) for _ in range(n)]
    vis = [[0 for _ in range(n)] for _ in range(n)]
    ans = 0
    temp = [-1,[]]
    dx = [0,1,0,-1]
    dy = [1,0,-1,0]
    for i in range(n):
        for j in range(n):
            maxcnt = -1
            vis[i][j] = 1
            dfs(i,j,1)
            if temp[0]<maxcnt:
                temp[0] = maxcnt
                temp[1] = [rooms[i][j]]
            elif temp[0]==maxcnt:
                temp[1].append(rooms[i][j])
    reslist.append((min(temp[1]),temp[0]))

for i in range(1,t+1):
    print("#"+str(i),reslist[i-1][0],reslist[i-1][1])