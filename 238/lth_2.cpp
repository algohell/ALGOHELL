class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        vector<int> toLeft;
        vector<int> toRight;
        
        int tl = 1;
        int tr = 1;
        for (int i = 0; i < size; ++i) {
            toRight.push_back(tr);
            toLeft.push_back(tl);
            tr *= nums[i];
            tl *= nums[size - i - 1];
        }
        for (int i = 0; i < size; ++i) {
            ans.push_back(toLeft[size - i - 1] * toRight[i]);
        }
        return ans;
    }
};