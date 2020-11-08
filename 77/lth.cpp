class Solution {
public:
    void comb(vector<vector<int>>& ans, vector<int>& curr, int n, int k, int idx) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i <= n; ++i) {
            curr.push_back(i);
            comb(ans, curr, n, k, i + 1);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        comb(ans, curr, n, k, 1);
        
        return ans;
    }
};