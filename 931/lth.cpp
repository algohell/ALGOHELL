class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int rowS = A.size();
        int colS = A[0].size();
        
        for (int i = rowS - 2; i >=0; --i) {
            for (int j = 0; j < colS; ++j) {
                if (j == 0) {
                    A[i][j] = A[i][j] + min(A[i+1][j], A[i+1][j+1]);
                }
                else if (j == colS - 1) {
                    A[i][j] = A[i][j] + min(A[i+1][j-1], A[i+1][j]);
                }
                else {
                    A[i][j] = A[i][j] + min({A[i+1][j-1], A[i+1][j], A[i+1][j+1]});
                }
            }
            
        }
        
        int minVal = 101;
        for (int i = 0; i < colS; ++i) {
            minVal = min(minVal, A[0][i]);
        }
        
        
        return minVal;
    }
};
