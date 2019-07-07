class Solution(object):
  def search(self, nums, target):
    left, right = 0, len(nums) - 1
    while left <= right:
      mid = (left + right) // 2
      print(left,right,mid)
      print("l",nums[left],"m",nums[mid],"r",nums[right])
      if nums[mid] == target:
          return mid
      if nums[left] <= nums[mid]:
        if target >= nums[left] and target < nums[mid]:
            right = mid - 1
        else:
            left = mid + 1
      else:
        if target <= nums[right] and target > nums[mid]:
            left = mid + 1
        else:
            right = mid - 1
    return -1

s = Solution()
nums = [4,5,6,7,0,1,2]
target = 0
print(s.search(nums, target))
