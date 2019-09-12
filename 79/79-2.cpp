
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
class Solution {
public:
    static bool find(vector<vector<char>>& board, vector<vector<bool>>& check, int x, int y, string word, int idx) {
        if (idx == word.size()) return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= board.size() || ny >= board[x].size() || nx < 0 || ny < 0 || check[nx][ny]) continue;
            if (word[idx] != board[nx][ny]) continue;
            check[nx][ny] = true;
            bool hasFound = find(board, check, nx, ny, word, idx + 1);
            check[nx][ny] = false;
            if (hasFound) return true;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int size = board.size();
        if (!size || !board[0].size()) return false;
        
        vector<vector<bool>> check(size, vector<bool>(board[0].size(),false));
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                check[i][j] = true;
                if (board[i][j] == word[0] && find(board, check, i, j, word, 1)) return true;
                check[i][j] = false;
            }
        }
        return false;
    }
};