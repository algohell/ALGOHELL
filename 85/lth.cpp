class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;
        vector<vector<pair<int, int>>> area(matrix.size(), vector<pair<int, int>>(matrix[0].size()));
        
        int maxA = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') continue;
                int left = j == 0 ? 1 : area[i][j-1].first + 1, up = i == 0 ? 1 : area[i-1][j].second + 1;
                area[i][j] = make_pair(left, up);
                int w = left, h = up;
                int len = min(w, h);
                for (int k = i; k >= i - len; --k) {
                    if ( k < 0 || matrix[k][j] == '0' ) break;
                    w = min(area[k][j].first, w);
                    maxA = max(maxA, (i - k + 1) * w);
                }
                for (int k = j; k >= j - len; --k) {
                    if ( k < 0 || matrix[i][k] == '0') break;
                    h = min(area[i][k].second, h);
                    maxA = max(maxA, (j - k + 1) * h);
                }
            }
        }
        return maxA;
    }
};