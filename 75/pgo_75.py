# 75. Sort Colors
from collections import Counter
nums=[2,0,2,1,1,0]

# quick sort 이용
#     #print(nums)
#     if len(nums) <= 1:
#         print(nums)
#     pivot = nums[len(nums) // 2]
#     #print(pivot)
#     lesser_nums, equal_nums, greater_nums = [], [], []

#     for n in nums:
#         if n < pivot:
#             lesser_nums.append(n)
#             #print('lesser_nums=', lesser_nums)
#         elif n > pivot:
#             greater_nums.append(n)
#             #print('greater_nums=', greater_nums)
#         else:
#             equal_nums.append(n)
#             #print('equal_nums=', equal_nums)
    
#     print(lesser_nums+equal_nums+greater_nums)


count = Counter(nums)
print(count)

for i in range(len(nums)):
    
    if i < count[0]:
        nums[i] = 0
    
    elif i < count[0] + count[1]:
        nums[i] = 1
    
    else:
        nums[i] = 2
        
print(nums)