class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        int cnt = size;
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for (int i = 0; i < size; ++i) {
            dp[i][i] = true;
            if (i > 0 && s[i-1] == s[i]) {
                dp[i-1][i] = true;
                ++cnt;
            }
        }
        for (int len = 3; len <= size; ++len) {
            for (int i = 0; i + len <= size; ++i) {
                int j = i + len - 1;
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};