class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, area = 0;
        while (l < r) {
            area = max(area, (r - l) * min(height[r], height[l]));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return area;
    }
};