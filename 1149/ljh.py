N = int(input())
color = [list(map(int,input().split())) for _ in range(N)]
temp = [[0 for _ in range(3)] for _ in range(N)]
temp[0] = color[0]

def find_mincost():
  for i in range(1,N):
    for j in range(3):
      temp[i][j] = color[i][j] + min(temp[i-1][j-1],temp[i-1][j-2])
  return min(temp[N-1])

print(find_mincost())
