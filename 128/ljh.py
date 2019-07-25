from collections import Counter
class Solution:
  def longestConsecutive(self, nums):
    if not nums:
      return 0
    num_list = sorted(list(set(nums)))
    if len(num_list) == 1:
      return 1
    num_diff = []
    temp = num_list[1]
    count = 0
    for i in range(0,len(num_list)):
      if i != len(num_list)-1:
        temp = num_list[i+1]
        diff = temp - num_list[i]
        if diff == 1:
          count += 1
        elif i!=0:
          num_diff.append(count)
          count = 0
      else:
        num_diff.append(count)

    return max(num_diff) + 1

nums = [100,4,200,1,3,2]
s = Solution()
print(s.longestConsecutive(nums))