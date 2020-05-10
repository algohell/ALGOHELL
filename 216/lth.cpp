class Solution {
public:
    void getAns(int curr, int sum, vector<int>& arr, int k, int n, vector<vector<int>>& ans) {
        if (arr.size() == k) {
            if (sum == n) {
                ans.push_back(arr);
            }
            return;
        }
        if (sum > n) return;
        
        for (int i = curr; i <= 9; ++i) {
            arr.push_back(i);
            getAns(i + 1, sum + i, arr, k, n, ans);
            arr.pop_back();
        }
        
        return;
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        vector<vector<int>> ans;
        
        getAns(1, 0, arr, k, n, ans);
        
        return ans;
    }
};