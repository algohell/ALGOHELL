class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int start = 0;
        for (int i = size; i > 1; i -= 2) {
            int len = i;
            while (--len) {
                int x = start;
                int y = start;
                int prev = matrix[x][y];
                for (; y < start + i - 1; ++y) {
                    swap(prev, matrix[x][y]);
                }
                for (; x< start + i - 1; ++x) {
                    swap(prev, matrix[x][y]);
                }
                for (; y> start; --y) {
                    swap(prev, matrix[x][y]);
                }
                for (; x> start; --x) {
                    swap(prev, matrix[x][y]);
                }
                swap(prev, matrix[start][start]);
            }
            ++start;
        }
    }
};
