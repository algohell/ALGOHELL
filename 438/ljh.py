from collections import defaultdict
class Solution:
    def findAnagrams(s, p):
        n = len(p)
        freq = defaultdict(int)
        result = []

        print(s[:n])
        for c1, c2 in zip(p, s[:n]):
            freq[c1] += -1
            freq[c2] += 1
            if freq[c1] == 0:
                del freq[c1]
            if freq[c2] == 0:
                del freq[c2]
            
        for c in s:
            print(c,freq[c])
            
        for i in range(len(s) - n):
            if not freq:
                result.append(i)
            freq[s[i]] += -1
            freq[s[i+n]] += 1
            if freq[s[i]] == 0:
                del freq[s[i]]
            if freq[s[i+n]] == 0:
                del freq[s[i+n]]

        if not freq:
            result.append(len(s) - n)
        return result

s = "baa"
p = "aa"
print(Solution.findAnagrams(s,p))