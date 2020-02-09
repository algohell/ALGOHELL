gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

res = -1
if sum(gas) < sum(cost):
    pass
else:
    diff = [g - c for g,c in zip(gas,cost)]
    for i in range(len(diff)):
        check = True
        seq_sum = 0
        for j in range(len(diff)):
            seq_sum += diff[(i+j) % len(diff)]
            if seq_sum < 0:
                check = False
                break
        if check:
            res = i
            break            
print(res)
            
        
    