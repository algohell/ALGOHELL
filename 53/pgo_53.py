# 53. Maximum Subarray
#nums = [-2,1,-3,4,-1,2,1,-5,4]
# Output: 6

#nums = [1]
# Output: 1

#nums = [-2,1]
# Output: 1

#nums = [-2,-1]
# Output: 1

curSum = 0
maxSum = -1
        
for i in range(len(nums)):
    if curSum < 0: curSum = 0
    curSum += nums[i]
    maxSum = max(curSum,maxSum)

print(maxSum)