class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool checkWord(vector<vector<char>>& board, vector<vector<bool>>& check, string curr, int idx, int i, int j) {
        if (idx == curr.size()) return true;
        bool find = false;
        check[i][j] = true;
        for (int x = 0; x < 4; ++x) {
            int ni = i + this->dx[x];
            int nj = j + this->dy[x];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && board[ni][nj] == curr[idx] && !check[ni][nj]) {
                find = find || checkWord(board, check, curr, idx + 1, ni, nj);
            }
        }
        check[i][j] = false;
        return find;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> first;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    first.push_back(make_pair(i, j));
                }
            }
        }
        vector<vector<bool>> check(board.size(), vector<bool>(board[0].size(), false));
        for (pair<int, int> grid : first) {
            if (checkWord(board, check, word, 1, grid.first, grid.second)) {
                return true;
            }
        }
        return false;
    }
};