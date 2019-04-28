class Solution {
    public int rob(int[] nums) {
        int answer = 0;
	// arr은 불연속적인 nums의 값들을 더한 배열
        int[] arr = new int[nums.length];

	// nums 배열 길이가 3 이하일 때 각각 처리
        if (nums.length == 0) {		
            return 0;
        } else if (nums.length == 1) {
            return nums[0];
        } else if (nums.length == 2) {
            return nums[0] < nums[1] ? nums[1] : nums[0];
        } else if (nums.length == 3) {
            return nums[0] + nums[2] < nums[1] ? nums[1] : nums[0] + nums[2];
        }

        arr[0] = nums[0];
        arr[1] = nums[1];
        arr[2] = nums[0] + nums[2];

	// 연속적이지 않게 최대값이 담기게 DP
        for (int i = 3; i < nums.length; i++) {
            arr[i] = nums[i] + Math.max(arr[i - 2], arr[i - 3]);
        }
	
	// 최대값이 나오는 경우가 2가지이므로 이들 값을 비교
        answer = arr[arr.length - 1] < arr[arr.length - 2] ? arr[arr.length - 2] : arr[arr.length - 1];

        return answer;
    }
}