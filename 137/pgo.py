from collections import Counter

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0

        n_d_c = dict(Counter(nums))

        for i, v in n_d_c.items():
            if v == 1:
                res = i

        return res