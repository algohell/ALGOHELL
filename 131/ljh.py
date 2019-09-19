class Solution:
    def partition(self, s: str) -> List[List[str]]:
        slist = [list(s)]
        dp = [slist[-1]]
        while dp:
            plist = dp.pop(0)
            temp = []
            for i in range(1,len(plist)):
                if plist[i-1] == plist[i]:
                    temp.append(plist[0:i-1]+[plist[i-1]+plist[i]]+plist[i+1:])
                try:
                    if plist[i-1] == plist[i+1]:
                        temp.append(plist[0:i-1]+[plist[i-1]+plist[i]+plist[i+1]]+plist[i+2:])
                except: pass
            dp.extend(temp)
            for t in temp:
                if t not in slist:
                    slist.append(t)
        
        return slist