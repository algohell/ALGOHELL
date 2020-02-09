class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        
        #print(trips)
        
        #print(capacity)
        
        farest = 0
        
        for num,start,end in trips:
            farest = max(farest, end)
            
        
        farest_space = [0] * farest
        
        #print(farest_space)
        
        for num,start,end in trips:
            for i in range(start,end):
                farest_space[i] += num
                
                if farest_space[i] > capacity:
                    return False
                
        return True