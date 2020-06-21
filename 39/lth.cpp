class Solution {
public:
    void findAns(vector<int>& candidates, vector<int>& arr, int target, int curr, int sum, vector<vector<int>>& ans) {
        if (sum >= target) {
            if (sum == target) {
                ans.push_back(arr);   
            }
            return;
        }
        
        for (int i = curr; i < candidates.size(); ++i) {
            arr.push_back(candidates[i]);
            findAns(candidates, arr, target, i, sum + candidates[i], ans);
            arr.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        
        findAns(candidates, arr, target, 0, 0, ans);
        
        return ans;
    }
};