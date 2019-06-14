class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inters) {
        sort(inters.begin(), inters.end());
        
        vector<vector<int>> ans;
        
        if (!inters.size()) return ans;
        
        int start = inters[0][0];
        int end = inters[0][1];
        
        for (vector<int>& inter: inters) {
            if (end < inter[0]) {
                ans.push_back({ start, end });
                start = inter[0];
                end = inter[1];
            }
            else {
                end = max(end, inter[1]);
            }
        }
        
        ans.push_back({ start, end });
        
        return ans;
    }
};