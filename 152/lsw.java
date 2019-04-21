class Solution {
    public int maxProduct(int[] nums) {
        int answer, max, min;
        
        if (nums.length == 0) {
            return 0;
        }
        
        answer = nums[0];
        max = nums[0];
        min = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > 0) {  // 양수
                max = Math.max(max * nums[i], Math.max(max, nums[i]));
                min = Math.min(min * nums[i], Math.min(min, nums[i]));
            } else {  // 음수
                int temp = max;
                max = Math.max(min * nums[i], nums[i]);
                min = Math.min(temp * nums[i], nums[i]);
            }
            answer = Math.max(answer, max);
        }
        
        return answer;
    }
}
