class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        int rot = end;
        start = 0;
        end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int rMid = (mid + rot) % nums.size();
            if (nums[rMid] == target) return rMid;
            if (nums[rMid] < target) {
                start = mid + 1;
            }
            else {
                end = mid-1;
            }
        }
        return -1;
    }
};