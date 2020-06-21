class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        
        temp,opt = 0,0
        
        for c in cost:
            temp, opt = opt, min(temp,opt) + c
            
        
        return min(temp,opt)