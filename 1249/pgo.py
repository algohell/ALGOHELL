class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        
        left = []
        right = []
        
        for i,c in enumerate(s):
            if c == '(':
                left.append(i)
                
            elif c == ')':
                if left:
                    left.pop()
                else:
                    right.append(i)
                     
        #print(left)
        #print(right)
        
        result = []
        for i,c in enumerate(s):
            if i not in left and i not in right:
                #print(c)
                result.append(c)
                
        return ''.join(result)