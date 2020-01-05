n = 8
q = "1 2 5 3 7 8 6 4"
q = list(map(int,q.split()))

cnt = 0
for i in range(n):
  if (q[i]-1)-i>2:
    cnt = -1
    break
  start = (q[i]-1)-2 # 원래 자리
  if start<0: start=0
  temp = len(list(filter(lambda x: x>q[i],q[start:i]))) # [1 [2 5 3(4) 7 8 6 4]]
  cnt+=temp

if cnt<0:
  print("Too chaotic")
else:
  print(cnt)
