class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];
        int result = 1, check = 0;
        
        for (int value : nums) {
            if (value == 0) {
                check++;
                continue;
            }
            result *= value;
            System.out.println(result);
        }
        
        if (check > 1) {
            Arrays.fill(answer, 0);
            return answer;
        } else if (check == 1) {
            for (int i = 0; i < answer.length; i++) {
                if (nums[i] == 0) {
                    answer[i] = result;
                } else {
                    answer[i] = 0;
                }
            }
        } else {
            for (int i = 0; i < answer.length; i++) {
                answer[i] = result / nums[i];
            }
        }
        
        return answer;
    }
}