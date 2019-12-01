from collections import Counter 
from itertools import permutations
import math
s = input()
l = 1
r = len(s)

sub_s = s[l-1:r]
cnt_s = Counter(sub_s)
palen = 0
bottom = 1
remain = 0
bottom_list = []
temp = ""
for k,v in cnt_s.items():
    if v>1:
        temp+=k*(v//2)
        palen += v//2
        bottom *= math.factorial(v//2)
        bottom_list.append(v//2)
        if v%2==1:
            remain+=1 
    else:
        remain+=1

case = math.factorial(palen)//bottom
if remain==0: 
    res = case
else: 
    res = case * remain

print(res%1000000007)