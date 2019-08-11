class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (!nums[i]) {
                nums.erase(nums.begin() + i);
                ++cnt;
            }
        }
        for (int i = 0; i < cnt; ++i) nums.push_back(0);
    }
};