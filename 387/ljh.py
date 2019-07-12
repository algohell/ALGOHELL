from collections import Counter
class Solution:
  def firstUniqChar(self, s):
    d = Counter(s)
    for c, count in d.items():
      if count == 1:
        return s.find(c)
    return -1

s = "loveleetcode"
sol = Solution()
print(sol.firstUniqChar(s))
