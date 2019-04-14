class Solution {
    public int maxSubArray(int[] nums) {
        int answer = nums[0], temp = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < temp + nums[i]) {	// 이용가치가 있음
                temp += nums[i];
            } else {		// 기존의 원소들이 오히려 해가 됨
                temp = nums[i];
            }
            answer = Math.max(answer, temp);		// 이용가치가 있는 nums[i]들을 담으면서 나오는 최대값
        }
        return answer;
    }
}
