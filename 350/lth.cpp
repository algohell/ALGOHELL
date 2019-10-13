class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> inter;
        for(int num:nums1) map[num]++;
        for(int num:nums2){
            if(map[num]) {
                map[num]--;
                inter.push_back(num);
            }
        } 
        return inter;
    }
};