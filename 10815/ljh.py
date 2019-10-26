N = int(input())
sg_card = set(map(int,input().split()))
M = int(input())
check_card = list(map(int,input().split()))
res = ['0' for _ in range(M)]

for i in range(len(check_card)):
  if check_card[i] in sg_card: res[i] = '1'

print(" ".join(res))