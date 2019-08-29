from collections import Counter
class Solution:
    def reorganizeString(self, S: str) -> str:
        S_count = Counter(S)
        S_len = len(S)
        S_count = dict(S_count.most_common())
        max_s = list(S_count.values())[0]
        
        if S_len - max_s < max_s - 1:
            return ""
        
        new = []
        while S_count:
            k = list(S_count.items())[0][0]
            v = list(S_count.items())[0][1]
            if len(list(S_count.items()))>1 and new and new[-1] == k:
                k_next = list(S_count.items())[1][0]
                new.append(k_next)
                S_count[k_next]-=1
                if S_count[k_next] == 0: del S_count[k_next]
                continue
            if len(list(S_count.items()))==1 and v>1:
                i = 1
                while S_count[k]:
                    if i!=len(new)-1 and (new[i-1] == k or new[i] == k or new[i+1] == k):
                        i += 1
                        continue
                    new.insert(i,k)
                    S_count[k] -= 1
                    i = 1
            else:
                new.append(k)
                S_count[k] -= 1
            if S_count[k] == 0: del S_count[k]
        
        S = "".join(new)
        return S