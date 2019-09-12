class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        snums = sorted(nums)
        idx=[]
        if nums==snums:
            return 0
        for i in range(len(nums)): 
            if snums[i]!=nums[i]: # sorted nums 와 nums 비교
                idx.append(i)
        return idx[-1]-idx[0]+1 # idx list중 최소 인덱스에서 최대 인덱스까지의 값을 리턴 