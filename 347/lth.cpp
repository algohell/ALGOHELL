class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, int>

        int idx = 0;
        auto begin = nums.begin();
        auto end = nums.end();
        while (idx < nums.size()) {
            int s = lower_bound(begin, end, nums[idx]) - begin;
            int e = upper_bound(begin, end, nums[idx]) - begin;
            pq.push(make_pair(e - s - 1, nums[idx]));
            idx = e;
        }
        
        vector<int> ans;
        while (!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};