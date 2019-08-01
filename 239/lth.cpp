class Solution {
    static void getMax(int s, int e, vector<int>& nums, int& maxN) {
        for (int i = s; i <= e; ++i) {
            maxN = max(maxN, nums[i]);
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int size = nums.size();
        if (size == 0 || k == 0) return ans;
        int maxN = nums[0];
        getMax(0, k - 1, nums, maxN);
        ans.push_back(maxN);
        for (int i = i + k; i < size; ++i) {
            if (nums[i - k] == maxN) {
                maxN = nums[i];
                getMax(i-k+1, i, nums, maxN);
            }
            maxN = max(maxN, nums[i]);
            ans.push_back(maxN);
        }
        return ans;
    }
};