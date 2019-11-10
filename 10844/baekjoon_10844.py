n = int(input())

nlist = [1] * 10
nlist[0] = 0

print(nlist)

for i in range(1, n):
    temp = [0] * 10
    
    for j in range(10):
        if(j == 0): # 10, 101
            temp[1] += nlist[j]
        
        elif(j == 9):
            temp[8] += nlist[j]
        
        else:
            temp[j-1] += nlist[j]
            temp[j+1] += nlist[j]

    nlist = temp

ans = sum(nlist) % 1000000000
print(ans)