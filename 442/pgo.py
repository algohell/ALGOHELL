from collections import Counter
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        c_n = Counter(nums)
        return sorted([i for i,v in c_n.items() if v == 2])