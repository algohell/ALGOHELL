class Solution(object):
    def maxSlidingWindow(self, nums, k):
        now = []
        if len(nums) != 0:
            for i in range(len(nums)-k+1):
                now.append(max(nums[i:i+k]))
            return now
        elif k >= len(nums) and len(nums) != 0:
            now.append(max(nums))
            return now
        elif len(nums)==0 or k==0:
            return []