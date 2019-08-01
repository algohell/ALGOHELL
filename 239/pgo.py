# 239 : https://leetcode.com/problems/sliding-window-maximum/

# 빈리스트 하나 만들어서 
# nums의 리스트가 k를 몇번 돌릴수있는지 알아내야함
# 알아 낸 후, 매번의 i:i+k 가장 큰값 확인 후 rl리스트에 넣는다
# rl 출력

#nums = [1,3,-1,-3,5,3,6,7]
#k = 3
#out = [3,3,5,5,6,7]

counts = len(nums) - k + 1

rl = []

if len(nums) < counts:
    return nums
else:
    for i in range(counts):
        rl.append(max(nums[i:i+k]))
return rl