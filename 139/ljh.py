class Solution:
    def wordBreak(self, s, wordDict):
      store = [False]*(len(s)+1)
      store[0] = True
      
      print(store)
      for i in range(1,len(s)+1):
        for j in range(i-1,-1,-1):
          print(j,i)
          if store[j] and s[j:i] in wordDict:
            store[i] = True
            break
      return store[-1]

s = "applepenapple"
wordDict = ["apple", "pen"]
sol = Solution()
print(sol.wordBreak(s, wordDict))