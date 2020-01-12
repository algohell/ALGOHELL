H,W = map(int,input().split())
A = [[0] + list(map(int,input().split())) + [0] for _ in range(H)]
A = [[0 for _ in range(W+2)]] + A + [[0 for _ in range(W+2)]]

# 3 3  
# 1 3 4
# 2 2 3
# 1 2 4

# [0, 0, 0, 0, 0]
# [0, 1, 3, 4, 0]
# [0, 2, 2, 3, 0]
# [0, 1, 2, 4, 0]
# [0, 0, 0, 0, 0]

cnt = 0
for i in range(1,H+2):
    for j in range(1,W+2):
        if A[i][j]!=0: cnt += 2 # top, bottom의 surface
        cnt += abs(A[i][j] - A[i-1][j]) + abs(A[i][j] - A[i][j-1]) # left, back side의 면적을 합
print(cnt)