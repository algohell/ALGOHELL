class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        int acc = 1;
        for (int i = 0; i < size; ++i) {
            ans.push_back(acc);
            acc *= nums[i];
        }
        acc = 1;
        for (int i = size - 1; i >= 0; --i) {
            ans[i] *= acc;
            acc *= nums[i];
        }
        return ans;
    }
};