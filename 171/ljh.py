class Solution:
    def titleToNumber(self, s: str) -> int:
        slist = list(s)
        ans = ord(slist.pop())-64
        for i in range(1,len(s)): 
            ans += ((26**i)*(ord(slist.pop())-64))
        return ans