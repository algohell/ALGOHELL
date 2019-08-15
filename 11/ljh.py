class Solution:
    def maxArea(self, height):
      i = 0
      j = len(height)-1
      max_area = 0
      while i < j:
        if height[i]<height[j]:
          area = height[i] * (j-i)
          i += 1
        else:
          area = height[j] * (j-i)
          j -= 1
        if max_area < area:
          max_area = area
      return max_area
s = Solution()
height = [1,8,6,2,5,4,8,3,7]
s.maxArea(height)
