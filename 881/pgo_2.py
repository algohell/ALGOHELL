class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
    
        p_s = sorted(people, reverse=True)    
        
        l = 0
        r = len(p_s) - 1
        
        while l <= r:
            if p_s[l] + p_s[r] <= limit:
                r += -1 # 까구로
                
            l += 1
            
        return l