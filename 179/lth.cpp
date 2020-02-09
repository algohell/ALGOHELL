bool cmp(string first, string second) {
    int fsize = first.length();
    int ssize = second.length();
    if (fsize == ssize) {
        return first < second;
    }
    string tmp = first;
    first = first + second;
    second = second + tmp;
    return first < second;
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNum;
        for (int num : nums) {
            strNum.push_back(to_string(num));
        }
        sort(strNum.begin(), strNum.end(), cmp);
        reverse(strNum.begin(), strNum.end());
        string ans = "";
        for (string str : strNum) {
            ans += str;
        }
        int size = ans.size();
        int idx = size - 1;
        
        while (idx >= 0 && ans[idx] == '0') --idx;
        
        return idx < 0 ? "0" : ans;
    }
};