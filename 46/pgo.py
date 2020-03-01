import itertools
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutation = itertools.permutations(nums, len(nums))
        
        ans = []
        
        for p in permutation:
            ans.append(list(p))
        
        return ans