# from collections import defaultdict
from collections import OrderedDict
# from queue import PriorityQueue

n,d = map(int,input().split())
exp = list(map(int, input().split()))
maxval = max(exp)

def activityNotifications(expenditure, d):
    old = 0
    new = d
    noti = 0
    maxval = max(expenditure)
    cdict = OrderedDict()
    for i in range(maxval+1):
        cdict[i]=0
    for e in expenditure[:d]:
        cdict[e]+=1
    for _ in range(len(expenditure)-d):
        median = 0
        mcount = 0
        for q in cdict.items():
            mcount += q[1]
            if mcount>d//2:
                if d%2!=0:
                    median = q[0]
                else:
                    median = q[0]
                    for left in range(q[0], -1, -1):
                        temp = list(cdict.items())[left]
                        mcount -= temp[1]
                        if mcount < d//2:
                            median = (left + q[0])/2
                            break
                break
            if q[1]>0: prevq = q
        if expenditure[new]>=median*2: noti+=1
        if expenditure[old]!=expenditure[new]:
            cdict[expenditure[old]]-=1
            cdict[expenditure[new]]+=1
        old+=1
        new+=1
    return noti

print(activityNotifications(exp,d))