from collections import Counter
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        
        res = []
        
        c_a1 = Counter(arr1)
        
        #print(c_a1)
        
        d_c_a1 = dict(c_a1)
        
        #print(d_c_a1)
        
        for i in arr2:
            res.extend([i]*(d_c_a1[i]))
            
        #print(res)
        
        res.extend(sorted([x for x in arr1 if x not in arr2]))
        
        return res