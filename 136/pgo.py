from collections import Counter
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        for i,v in Counter(nums).items():
            if v == 1:
                return i