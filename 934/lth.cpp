int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int size = A.size();
        int mark = 1;
        queue<pair<int, int>> q;
        vector<vector<bool>> check(size + 1, vector<bool>(size + 1));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!check[i][j] && A[i][j] == 1) {
                    q.push(make_pair(i, j));
                    check[i][j] = true;
                    while (!q.empty()) {
                        int x, y;
                        tie(x, y) = q.front();
                        A[x][y] = mark;
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < size && ny >= 0 && ny < size && !check[nx][ny] && A[nx][ny] == 1) {
                                check[nx][ny] = true;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                    mark = -mark;
                }
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (A[i][j] == 1) q.push(make_pair(i, j));
            }
        }
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    if (A[nx][ny] == 0) {
                        A[nx][ny] = A[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                    else if (A[nx][ny] == -1) {
                        return A[x][y] - 1;
                    }
                }
            }
        }
        return 0;
    }
};