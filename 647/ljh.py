class Solution:
  def countSubstrings(self, s: str) -> int:
      count = 0
      for i in range(1,len(s)+1):
          for j in range(len(s)-i+1):
              win = s[j:j+i]
              if win == win[::-1]:
                  print(win)
                  count += 1
      print(count)
      return count
s = Solution()
string = "aaa"
s.countSubstrings(string)