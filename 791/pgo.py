class Solution:
    def customSortString(self, S: str, T: str) -> str:
        ans = ""
        for s_i in S:
            for t_i in T:
                if t_i in s_i:
                    #print(t_i)
                    ans = ans + t_i
                    #print(ans)

        for t_i in T:
            if t_i not in S:
                #print(t_i)
                ans = ans + t_i
                
        return ans