class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        if numRows <= 0:
            return []
        
        l = []
        
        for i in range(numRows):
            r = []
            
            for j in range(i):
                if j == 0:
                    r.append(1)
                    
                else:
                    r.append(l[-1][j-1] + l[-1][j])
                    
            r.append(1)
                
            l.append(r)
                
        return l