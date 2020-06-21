class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        res = [] #
        temp = [] # 현 candidates값과 temp 값들을 이용해서 target 값과 비교
        candidates.sort()
        index = 0

        def dfs(res, temp, c_s, index, target):
            for i in range(index, len(c_s)):
                
                compareValue = sum(temp) + c_s[i])
                
                if compareValue == target: # temp 합과 candidates 더한 값이 target과 같으면 append
                    res.append(temp+[c_s[i]]) 
                    
                elif compareValue < target: # 작으면 그 다음 노드로
                    dfs(res, temp+[c_s[i]], c_s, i, target)
 
                else: # 크면 리턴
                    return
        
        dfs(res, temp, candidates, index, target)
        
        return res
        