class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> alpha(26, 0);
        vector<int> check(26, 0);
        int sSize = s.size();
        int pSize = p.size();
        
        for (char c : p) {
            alpha[c-'a']++;
        }
        int l = 0;
        int r = 0;
        int len = 0;
        while (r < sSize) {
            int curr = s[r] - 'a';
            check[curr]++;
            ++len;
            if (alpha[curr] == 0) {
                while (l <= r) {
                    --check[s[l++] - 'a'];
                }
                len = 0;
                r = l;
            }
            else if (alpha[curr] < check[curr]) {
                while (s[l] != s[r]) {
                    --check[s[l++] - 'a'];
                    --len;
                }
                --check[s[l++] - 'a'];
                --len;
                ++r;
            }
            else {
                if (len == pSize) {
                    ans.push_back(l);
                    while (++r < sSize && s[l] == s[r]) {
                        check[s[l]-'a']--;
                        check[s[r]-'a']++;
                        ans.push_back(++l);
                    }
                    if (r >= sSize) return ans;
                    check[s[l]-'a']--;
                    ++l;
                    --len;
                }
                else {
                    ++r;
                }
            }
        }
        return ans;
    }
};