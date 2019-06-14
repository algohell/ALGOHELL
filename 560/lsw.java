class Solution {
    public int subarraySum(int[] nums, int k) {
        int answer = 0;
        
        for (int i = 0; i < nums.length; i++) {
            answer += countEqual(nums, i, k);
        }
        
        return answer;
    }
    
    public int countEqual(int[] nums, int from, int k) {
        int result = 0;
        int sum = 0;
        
        for (int i = from; i < nums.length; i++) {
            sum += nums[i];
            if (sum == k) {
                result++;
            }
        }
        
        return result;
    }
}
