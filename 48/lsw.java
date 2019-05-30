class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i + 1; j < matrix[i].length; j++) {
                swap(matrix, i, j);
            }
        }
        
        for (int i = 0; i < matrix.length / 2; i++) {
            swapColumn(matrix, i, matrix.length - 1 - i);
        }
    }
    
    public void swap(int[][] matrix, int row, int col) {
        int temp = matrix[row][col];
        matrix[row][col] = matrix[col][row];
        matrix[col][row] = temp;
    }
    
    public void swapColumn(int[][] matrix, int col, int oppositeCol) {
        for (int row = 0; row < matrix.length; row++) {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[row][oppositeCol];
            matrix[row][oppositeCol] = temp;
        }
    }
}
