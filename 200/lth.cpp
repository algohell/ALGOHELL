class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void markIsland(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        grid[i][j] = '#';
        while(!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + this->dx[d];
                int ny = y + this->dy[d];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                    q.push(make_pair(nx, ny));
                    grid[nx][ny] = '#';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    this->markIsland(grid, i, j, rows, cols);
                    ++ans;
                }
            }
        }
        return ans;
    }
};