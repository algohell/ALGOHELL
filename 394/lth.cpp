class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> st;
        int num = 0;
        string ans;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                nums.push(num);
                st.push(ans);
                ans = "";
                num = 0;
            }
            else if (c == ']') {
                string temp = st.top();
                for (int i = 0; i < nums.top(); ++i) {
                    temp += ans;
                }
                ans = temp;
                st.pop();
                nums.pop();
            }
            else {
                ans += c;
            }
        }
        
        return ans;
    }
};