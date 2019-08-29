import sys
class Solution:
    def maxSubArray(self, nums):
        res = -sys.maxsize -1
        subsum = nums[0]
        for i in range(1,len(nums)):
          subsum = max(nums[i],nums[i]+subsum)
          res = max(subsum,res)
        return max(res,nums[0])

s = Solution()
nums = [5,-1,-2,-3]
s.maxSubArray(nums)