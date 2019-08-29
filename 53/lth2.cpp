class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxN = INT_MIN, idx = 0;
        while (idx < nums.size()) {
            sum = sum < 0 ? nums[idx] : sum + nums[idx];
            maxN = max(maxN, sum);
            ++idx;
        }
        return max(maxN, sum);
    }
};