class Solution {
public:
    string decode(string s, int& idx) {
        string curr = "";
        while (idx < s.size() && s[idx] != ']') {
            if (isdigit(s[idx])) {
                int k = s[idx] - '0';
                while (s[++idx] != '[') {
                    k = k * 10 + (s[idx] - '0');
                }
                ++idx; // 숫자 -> [
                string tmp = decode(s, idx);
                ++idx; // ] -> 알파벳
                for (int i = 0; i < k; ++i) {
                    curr += tmp;
                }
            }
            else {
                curr += s[idx++];
            }
        }
        return curr;
    }
    string decodeString(string s) {
        int idx = 0;
        return decode(s, idx); 
    }
};