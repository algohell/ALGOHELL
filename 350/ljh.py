from collections import Counter
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        anslist = []
        c1 = Counter(nums1)
        c2 = Counter(nums2)
        for k in nums1:
            if c1[k]>0 and c2[k]>0:
                c1[k] -= 1
                c2[k] -= 1
                anslist.append(k)
        return anslist