class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> m;
        vector<pair<int, char>> v;
        for (char c : s) {
            m[c]++;
        }
        for (pair<char, int> curr : m) {
            if (curr.second) {
                v.push_back(make_pair(curr.second, curr.first));
            }
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        for (pair<int, char> curr : v) {
            while(curr.first--) ans += curr.second;
        }
        return ans;
    }
};