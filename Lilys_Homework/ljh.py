def lilysHomework(arr):
    d = {}
    for i in range(n): d[i] = arr[i]
    d = sorted(d.items(),key=lambda x: x[1])
    dr = sorted(d,key=lambda x: x[1],reverse=True)
    cnt,rcnt = 0,0

    vis = [0 for _ in range(n)]
    for i in range(n):
        if vis[i]==1 and d[i][0]==i: continue
        temp = i
        tempcnt = 0
        while vis[temp]==0:
            vis[temp]+=1
            temp = d[temp][0]
            tempcnt+=1
        if tempcnt>0: cnt+=(tempcnt-1)

    vis = [0 for _ in range(n)]
    for i in range(n):
        if vis[i]==1 and dr[i][0]==i: continue
        temp = i
        tempcnt = 0
        while vis[temp]==0:
            vis[temp]+=1
            temp = dr[temp][0]
            tempcnt+=1
        if tempcnt>0: rcnt+=(tempcnt-1)
        
    return min(cnt,rcnt)

n = int(input())
arr = list(map(int, input().rstrip().split()))
result = lilysHomework(arr)
