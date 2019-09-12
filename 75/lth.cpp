class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0,};
        for (int num : nums) cnt[num]++;
        int idx = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                nums[idx + j] = i;
            }
            idx += cnt[i];
        }
    }
};