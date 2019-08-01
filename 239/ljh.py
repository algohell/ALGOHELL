from collections import deque
class Solution(object):
    def maxSlidingWindow(self, nums, k):
      if not nums:
        return []
      max_list = []
      q = deque(nums[0:k])
      for i in range(len(nums)-(k-1)):
        max_list.append(max(q))
        try:
          q.popleft()
          q.append(nums[i+k])
        except:
          break
      return max_list
s = Solution()
nums = [1,3,-1,-3,5,3,6,7]
k = 3
s.maxSlidingWindow(nums,k)