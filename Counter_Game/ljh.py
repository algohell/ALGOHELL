import math

n = int(input())
cnt = 0

while n != 1:
    cnt += 1
    l = math.log2(n)

    if (l - int(l)) == 0:
        n = n // 2
    else:
        n = n - 2**int(l)

if cnt % 2 == 0:
    print("Richard")
else:
    print("Louise")