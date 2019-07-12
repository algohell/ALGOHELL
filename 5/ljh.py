class Solution:
    def longestPalindrome(self, s):
      if not s:
        return ""

      len_list = []
      window = []
      
      for i in range(2,len(s)+1):#window size
        for j in range(0,len(s)-(i-2)):#sliding window
          window = s[j:(j+i)]
          if window[::-1] == window:
            len_list.append(window)

      if not len_list:
        return s[0]
      else:
        res=max(len_list,key=len)
        return res

s = "ccc"
sol = Solution()
print("res = ",sol.longestPalindrome(s))