class Solution:
  def climbStairs(self, n):
    if n < 4:
      return n
    prev_f = 2
    prev_b = 3
    for i in range(3,n):
      climb = prev_f + prev_b
      prev_f = prev_b
      prev_b = climb
    print(climb)
    return climb
s = Solution()
n = 4
s.climbStairs(n)