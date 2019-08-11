class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if (size == 0) return size;
        int maxLen = 1;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < size; ++i) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for (int i = 0; i < size; ++i) {
            maxLen = max(dp[i], maxLen);
        }
        return maxLen;
    }
};