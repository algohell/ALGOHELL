class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string word: wordDict) {
            words.insert(word);
        }
        for (int i = 1; i <= s.size(); ++i) {
            if (words.count(s.substr(0, i))) continue;
            for (int j = i; j >= 0; --j) {
                if (words.count(s.substr(0, j)) && words.count(s.substr(j, i - j))) {
                    words.insert(s.substr(0, i));
                    break;
                }
            }
        }
        return !!words.count(s);
    }
};