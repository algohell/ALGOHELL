from collections import Counter
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        n_c = Counter(nums)
        
        res = []
        
        for i,v in n_c.items():
            if v == 1:
                res.append(i)
        
        return res