class Solution:
    def subsets(nums):
      total_len = 2**len(nums)
      # print(total_len)
      total_sub = []

      for i in range(total_len):
        subset=[]
        print("--------------")
        for num in nums:
          print("i = ",i)
          if(i%2==0):
            subset.append(num)
            print("subset = ",subset)
          i//=2
        total_sub.append(subset)  
      return total_sub

nums = [0,1,2,3,4]
print(Solution.subsets(nums))

