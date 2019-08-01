int rows[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int cols[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
class Solution {
    
    static void check(vector<vector<int>>& board, int r, int c, int& rSize, int& cSize) {
        int curr = board[r][c];
        int lives = 0;
        for (int i = 0; i < 8; ++i) {
            int nr = r + rows[i];
            int nc = c + cols[i];
            if (nr >= 0 && nr < rSize && nc >= 0 && nc < cSize && board[nr][nc]) {
                ++lives;
            }
        }
        if (curr == 1) curr = lives >= 2 && lives <= 3;
        else curr = lives == 3;
        if (c + 1 < cSize) {
            check(board, r, c + 1, rSize, cSize);
        }
        else if (r + 1 < rSize) {
            check(board, r + 1, 0, rSize, cSize);
        }
        board[r][c] = curr;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rSize = board.size();
        int cSize = rSize ? board[0].size() : 0;
        if (rSize && cSize) {
            check(board, 0, 0, rSize, cSize);
        }
    }
};