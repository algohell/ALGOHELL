nk = input().split()
n = int(nk[0])
k = int(nk[1])
r_qC_q = input().split()
r_q = int(r_qC_q[0])
c_q = int(r_qC_q[1])
obstacles = []
for _ in range(k):
    obstacles.append(list(map(int, input().rstrip().split())))

# board = [["#"]+["0" for _ in range(n)] for _ in range(n)]
# board = [["#" for _ in range(n+1)]] + board
# board[r_q][c_q] = "Q"
# for o in obstacles:
#   board[o[0]][o[1]] = "#"

# ans = 0
# dx = [-1,0,1,0,1,-1,1,-1]
# dy = [0,-1,0,1,1,-1,-1,1]
# def dfs(r,c,direction):
#   global ans
#   
#   if direction>=len(dx):
#     return
#   if r>n or c>n or board[r][c]=="#":
#       dfs(r_q,c_q,direction+1)
#   elif board[r][c]=="0" or board[r][c]=="Q":
#     if board[r][c]!="Q":
#       board[r][c]="1"
#       ans+=1
#     dfs(r+dx[direction],c+dy[direction],direction)
# dfs(r_q,c_q,0)

widthl,widthr = n//2,n//2
heightu,heightd = n//2,n//2
rdown_t,rdown_b = min(r_q,c_q)-1,n-max(r_q,c_q)
rup_t,rup_b = min(r_q-1,n-c_q),min(n-r_q,c_q-1)
prevw_l,prevw_r = -1,n+1
prevh_u,prevh_d = -1,n+1
prevrd_t,prevrd_b = -1,n+1
prevru_t,prevru_b = n+1,-1
for o in obstacles:
    if o[0] == r_q:
        if prevw_l<o[1]<c_q:
            widthl = (n//2) - o[1]
            prevw_l = o[1]
        elif c_q<o[1]<prevw_r:
            widthr = (n//2) - ((n-o[1])+1)
            prevw_r = o[1]
    elif o[1] == c_q:
        if prevh_u<o[0]<r_q :
            heightu = (n//2) - o[0]
            prevh_u = o[0]
        elif r_q<o[0]<prevh_d:
            heightd = (n//2) - ((n-o[0])+1)
            prevh_d = o[0]
    elif r_q-o[0] == c_q-o[1]:
        if prevrd_t<o[1]<c_q:
            rdown_t = (min(r_q,c_q)-1) - min(o[0],o[1])
            prevrd_t = o[1]
        elif c_q<o[1]<prevrd_b:
            rdown_b = (n-max(r_q,c_q)) - ((n-max(o[0],o[1]))+1)
            prevrd_b = o[1]
    elif abs(r_q-o[0]) == abs(c_q-o[1]):
        if prevru_b<o[1]<c_q:
            rup_b = (min(n-r_q,c_q-1)) - min((n-o[0])+1,o[1])
            prevru_b = o[1]
        elif c_q<o[1]<prevru_t:
            rup_t = (min(r_q-1,n-c_q)) - min(o[0],(n-o[1])+1)
            prevru_t = o[1]
if n%2==0:
    width = widthl + widthr - 1
    height = heightu + heightd - 1
else:
    width = widthl + widthr
    height = heightu + heightd

print(width+height+rdown_t+rdown_b+rup_t+rup_b)