class Solution {
public:
    bool rotateString(string A, string B) {
        string db = B + B;
    
        return (A.size() == B.size()) && db.find(A) != string::npos;
    }
};