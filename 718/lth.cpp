class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int dp[101][101];
        int maxLen = 0;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    if (i-1 >= 0 && j-1 >= 0) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = 1;   
                    }
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        
        return maxLen;
    }
};