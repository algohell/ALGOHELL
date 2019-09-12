class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> cp = nums;
        int size = nums.size();
        sort(cp.begin(), cp.end());
        int s = 0, e = nums.size() - 1;
        while (s < size && nums[s] == cp[s]) ++s;
        while (e >= 0 && nums[e] == cp[e]) --e;
        
        return s >= size || e < 0 ? 0 : e - s + 1;
    }
};