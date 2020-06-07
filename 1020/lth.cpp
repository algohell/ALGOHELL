class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void visit(int x, int y, int rowS, int colS, vector<vector<int>>& A, vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        
        if (A[x][y] == 0) return;
        
        visited[x][y] = true;
        
        
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = dx[k] + curr.first;
                int ny = dy[k] + curr.second;

                if (nx < 0 || nx >= rowS || ny < 0 || ny >= colS || A[nx][ny] == 0 || visited[nx][ny]) {
                    continue;
                }
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        vector<vector<int>> visited(501, vector<int>(501, false));
        int rowS = A.size();
        int colS = A[0].size();
        
        for (int i = 0; i < rowS; ++i) {
            if (i == 0 || i == rowS - 1) {
                for (int j = 0; j < colS; ++j) {
                    visit(i, j, rowS, colS, A, visited);
                }
            }
            else {
                for (int j = 0; j < 2; ++j) {
                    int y = j == 0 ? j : colS - 1;
                    visit(i, y, rowS, colS, A, visited);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < rowS; ++i) {
            for (int j = 0; j < colS; ++j) {
                if (A[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};