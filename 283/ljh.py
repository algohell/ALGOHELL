class Solution:
    def moveZeroes(self, nums):
        for i in range(nums.count(0)):
            nums.remove(0)
            nums.append(0)
