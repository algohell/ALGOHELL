class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        int max = 1;
        // �����ϴ� ������ ������ ���� �迭
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1); // �ʱⰪ 1

        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > max) {
                max = dp[i]; // dp �迭�� �ִ밪�� ����
            }
        }

        return max;
    }
}