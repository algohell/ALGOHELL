import java.util.Arrays;

class Solution {
    public int majorityElement(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        Arrays.sort(nums);
        int count = 1;
        int answer = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] == nums[i]) {
                count++;
            } else {
                count = 1;
                answer = nums[i];
            }
            if (count > nums.length / 2) {
                break;
            }
        }
        
        return answer;
    }
}