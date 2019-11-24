vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> rank;
    vector<int> ans;
    rank.push_back(1);
    for (int i = 1; i < scores.size(); ++i) {
        if (scores[i] == scores[i-1]) {
            rank.push_back(rank[i-1]);
        }
        else {
            rank.push_back(rank[i-1] + 1);
        }
    }
    reverse(scores.begin(), scores.end());
    reverse(rank.begin(), rank.end());

    for (int a : alice) {
        int idx = upper_bound(scores.begin(), scores.end(), a) - scores.begin();
        if (idx == scores.size()) {
            ans.push_back(1);
        }
        else {
            ans.push_back(rank[idx] + 1);
        }
    }
    return ans;
}