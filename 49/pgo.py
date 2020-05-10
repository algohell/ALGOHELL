from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        d_l = defaultdict(list)
        
        for s in strs:
            words = "".join(sorted(s))
            print(words)
            
            d_l[words] += [s]
            
        return d_l.values()