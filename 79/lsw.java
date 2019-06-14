class Solution {
    private boolean[][] visited;
    
    public boolean exist(char[][] board, String word) {
        visited = new boolean[board.length][board[0].length];
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == word.charAt(0) && DFS(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    public boolean DFS(char[][] board, String word, int row, int col, int index) {
        if (row >= board.length || row < 0
                || col >= board[row].length || col < 0
                || board[row][col] != word.charAt(index)
                || visited[row][col] == true) {
            return false;
        }
        if (index == word.length() - 1) {
            return true;
        }

        visited[row][col] = true;
        if (DFS(board, word, row, col + 1, index + 1)
                || DFS(board, word, row, col - 1, index + 1)
                || DFS(board, word, row + 1, col, index + 1)
                || DFS(board, word, row - 1, col, index + 1)) {
            return true;
        }
        visited[row][col] = false;

        return false;
    }
}
