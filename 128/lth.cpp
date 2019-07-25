class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans = nums.size() > 0 ? 1 : 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!cnt.count(nums[i])) {
                cnt[nums[i]] = 1;
            }
        }
        for (int num : nums) {
            int len = 1;
            int l = num - 1;
            int h = num + 1;
            while (cnt.count(l) && cnt[l]) {
                cnt[l] = 0;
                --l;
                ++len;
            }
            while (cnt.count(h) && cnt[h]) {
                cnt[h] = 0;
                ++h;
                ++len;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};