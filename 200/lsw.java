class Solution {
    public int numIslands(char[][] grid) {
        int answer = 0;
        
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    change(grid, i, j);
                    answer++;
                }
            }
        }
        
        return answer;
    }
    
    public void change(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        change(grid, i + 1, j);
        change(grid, i - 1, j);
        change(grid, i, j + 1);
        change(grid, i, j - 1);
    }
}
