wine = int(input())

wlist = [0]

for i in range(wine):
    wlist.append(int(input()))

#print(wlist)

ans = wlist.copy()

#print(ans)

for i in range(1, wine + 1):
    if i == 1: # 1번째 포도주까지 최대로 마실수 있는 포도주
        ans[1] = wlist[1] 

    elif i == 2: # 2번째 포도주까지
        ans[2] = wlist[1] + wlist[2]

    else: # 3번째 이상
        ans[i] = max(ans[i-1], # 이번차례에 마시지 X 
                     ans[i-2]+ wlist[i], # 직전에 마시지 x, 이번에 마셨을때
                     ans[i-3] + wlist[i-1] + wlist[i] # 이번과 직전에 마시고, 그 전에 마시지 X
                     )
print(ans)
print(ans[-1])