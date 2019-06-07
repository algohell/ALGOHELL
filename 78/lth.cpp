class Solution {
public:
    void getSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int curr) {
        ans.push_back(temp);
        if (nums.size() <= curr) return;
        for (int i = curr; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            getSubsets(nums, ans, temp, i + 1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        getSubsets(nums, ans, temp, 0);
        return ans;
    }
};