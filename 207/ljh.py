class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        pre = prerequisites
        pdict = dict(((n,[]) for n in range(numCourses)))
        for p in pre:
            pdict[p[0]].append(p[1])
            
        def dfs(pdict,n,vis):
            if vis[n]==-1:
                return True
            vis[n] = -1
            for c in pdict[n]:
                if dfs(pdict,c,vis):
                    return True
            vis[n] = 1
            return False
        
        for num in range(numCourses):
            vis = dict(((n,0) for n in range(numCourses)))
            if dfs(pdict,num,vis):
                return False
        return True