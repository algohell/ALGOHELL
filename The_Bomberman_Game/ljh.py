r,c,n = map(int,input().split())
grid = [[x for x in input()] for _ in range(r)]

def bomberMan(n, grid):
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    
    if n == 1:
        return grid
    if n%2 == 0:
        temp = ['O'*c for _ in range(r)]
        return temp

    temp = [[['O' for _ in range(c)] for _ in range(r)] for _ in range(2)]

    for t in range(2):
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 'O':
                    temp[t][i][j] = '.'
                else:
                    for d in range(4):
                        if 0<=i+dx[d]<r and 0<=j+dy[d]<c:
                            if grid[i+dx[d]][j+dy[d]] == 'O':
                                temp[t][i][j] = '.'
                                break
        grid = temp[t]

    for i in range(r):
        temp[0][i] = ''.join(temp[0][i])

    for i in range(r):
        temp[1][i] = ''.join(temp[1][i])

    if (n-3)%4==0:
        return temp[0]
    else:
        return temp[1]

result = bomberMan(n, grid)