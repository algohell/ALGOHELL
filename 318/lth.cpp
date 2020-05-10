class Solution {
static bool compare(string a, string b) {
    return a.size() < b.size();
}
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        for (string word: words) {
            sort(word.begin(), word.end());
        }
        int ans = 0;
        for (int i = words.size() - 1; i >= 1; --i) {
            if (words[i].size() * words[i - 1].size() <= ans) {
                continue;
            }
            for (int j = i - 1; j >= 0; --j) {
                bool dup = false;
                for (int k = 0; k < words[i].size(); ++k) {
                    for (int l = 0; l < words[j].size(); ++l) {
                        if (words[i][k] == words[j][l]) {
                            dup = true;
                            break;
                        }
                    }
                    if (dup) break;
                }
                if (!dup && ans < words[i].size() * words[j].size()) {
                    ans = words[i].size() * words[j].size();
                }
            }
        }
        return ans;
    }
};