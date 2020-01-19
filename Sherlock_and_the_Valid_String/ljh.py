from collections import Counter

s = input()

slist = [c for c in s]
ans = "NO"

val = list(Counter(slist).values())
val_cnt = list(Counter(val).items())

if len(val_cnt) == 1:
  ans = "YES"
elif len(val_cnt) == 2:
  for i in range(len(val_cnt)):
    if val_cnt[i][1] == 1:
      if (val_cnt[i][0] - 1) == val_cnt[i-1][0] or (val_cnt[i][0] - 1) == 0:
        ans = "YES"

print(ans)