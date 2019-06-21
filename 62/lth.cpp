class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n+1);
        dp[n - 1] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[j] += dp[j + 1];
            }
        }
        return dp[0];
    }
};