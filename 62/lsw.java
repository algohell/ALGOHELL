class Solution {
    int[][] pathCount;
    
    public int uniquePaths(int m, int n) {
        pathCount = new int[n][m];
        initializeColumn(m);
        initializeRow(n);
        addUpAndRightValue(m, n);
        return pathCount[n - 1][m - 1];
    }
    
    public void initializeColumn(int m) {
        for (int i = 0; i < m; i++) {
            pathCount[0][i] = 1;
        }
    }
    
    public void initializeRow(int n) {
        for (int i = 0; i < n; i++) {
            pathCount[i][0] = 1;
        }
    }
    
    public void addUpAndRightValue(int m, int n) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                pathCount[i][j] = pathCount[i - 1][j] + pathCount[i][j - 1];
            }
        }
    }
}
