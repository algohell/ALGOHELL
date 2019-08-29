# 215. Kth Largest Element in an Array
#nums = [3,2,1,5,6,4]
#k = 2
# Output: 5

#nums = [3,2,3,1,2,4,5,5,6]
#k = 4
# Output: 4

sortedNums = sorted(nums, reverse=True)
print(sortedNums[k-1])