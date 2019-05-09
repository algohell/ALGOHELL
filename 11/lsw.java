class Solution {
    public int maxArea(int[] height) {
        int right = height.length - 1, left = 0;
        int answer = Integer.MIN_VALUE;
        
        if (height.length <= 1) {
            return 0;
        }
        
        while (left < right) {	// 겹치지 않을 때까지
            int x = right - left;
            int y = height[left] < height[right] ? height[left] : height[right];
            answer = Math.max(answer, x * y);	// 넓이의 최대값을 answer에
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return answer;
    }
}