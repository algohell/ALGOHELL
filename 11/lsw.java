class Solution {
    public int maxArea(int[] height) {
        int right = height.length - 1, left = 0;
        int answer = Integer.MIN_VALUE;
        
        if (height.length <= 1) {
            return 0;
        }
        
        while (left < right) {	// ��ġ�� ���� ������
            int x = right - left;
            int y = height[left] < height[right] ? height[left] : height[right];
            answer = Math.max(answer, x * y);	// ������ �ִ밪�� answer��
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return answer;
    }
}