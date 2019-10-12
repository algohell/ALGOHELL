class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        ans = 1
        for n in nums:
            if n == ans:
                ans+=1
        
        return ans