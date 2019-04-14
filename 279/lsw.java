import java.util.Arrays;

class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);     // 초기화
        dp[0] = 0;      // dp를 위한 첫번째 값
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {      // 제곱값이 i보다 작거나 같을 때까지 반복
                dp[i] = Math.min(dp[i - j * j] + 1, dp[i]);     // 이전의 dp 원소 + 제곱값 = 최적값
            }
        }
        
        return dp[n];
    }
}
