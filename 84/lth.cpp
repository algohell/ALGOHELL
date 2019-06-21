class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int size = heights.size();
        if (!size) return 0;
        vector<int> minH(size);
        minH[0] = heights[0];
        for (int i = 1; i < size; ++i) {
            minH[i] = min(minH[i-1], heights[i]);
        }
        for (int i = 0; i < size; ++i) {
            int area = heights[i];
            int currMin = heights[i];
            int left = i - 1;
            while (left >= 0 && currMin != minH[i]) {
                currMin = min(currMin, heights[left]);
                area = max(area, (i - left + 1) * currMin);
                --left;
            }
            ans = max({ans, area, minH[i] * (i + 1)});
        }
        return ans;
    }
};