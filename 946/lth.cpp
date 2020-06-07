class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        queue<int> q;
        
        for (int i = 0; i < popped.size(); ++i) {
            q.push(popped[i]);
        }
        int i = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            while (i < pushed.size()) {
                int ci = i;
                st.push(pushed[i]);
                i += 1;
                if (pushed[ci] == curr) {
                    break;
                }
            } 
            if (st.top() != curr) {
                return false;
            }
            while (!st.empty() && (st.top() == curr)) {
                st.pop();
                q.pop();
                curr = q.front();
            }
        }
        
        return true;
    }
};