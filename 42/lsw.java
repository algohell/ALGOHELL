class Solution {
    
    static int[] water;
    
    public int trap(int[] height) {
        water = new int[height.length];
        int right = 0, answer = 0;
        
        if (height.length == 0 || height.length == 1 || height.length == 2) {
            return answer;
        }
        
        while (height[right] == 0) {
            right++;
        }
        
        for (int i = right + 1; i < height.length; i++) {
            calculateRightAndLeftArea(height, right, i);
            if (height[i] >= height[right]) {
                right = i;
            }
        }
        
        for (int value : water) {
            answer += value;
        }
        
        return answer;
    }
    
    public void calculateRightAndLeftArea(int[] height, int right, int left) {
        int dimension = 0;
        int minHeight = height[right] > height[left] ? height[left] : height[right];
        
        for (int i = right + 1; i < left; i++) {
            water[i] = Math.max(water[i], minHeight - height[i]);
        }
    }
}