from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        c = sorted(list(Counter(list(s)).items()),key=lambda x: x[1],reverse=True)
        res = []
        for item in c:
            res.append(item[0]*item[1])
        s = ''.join(res)
        return s