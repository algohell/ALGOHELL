class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> map;
        for (int num: arr1) {
            map[num]++;
        }
        vector<int> ans;
        for (int num: arr2) {
            int cnt = map[num];
            for (int i = 0; i < cnt; ++i) {
                ans.push_back(num);
                --map[num];
            }
        }
        int st = ans.size();
        for (auto& it: map) {
            for (int i = 0; i < it.second; ++i) {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin() + st, ans.end());
        
        return ans;
    }
};