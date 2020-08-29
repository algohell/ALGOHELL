class Solution {
public:
    bool check(int curr, vector<bool>& visit, vector<int>& group, unordered_map<int, vector<int>>& map) {
        if (visit[curr]) {
            return true;
        }
        visit[curr] = true;
        group[curr] = group[curr] == 0 ? 1 : group[curr];
        
        for (int j = 0; j < map[curr].size(); ++j) {
            int dislike = map[curr][j];
                
            if (group[curr] == group[dislike]) {
                return false;
            }
                
            group[dislike] = group[curr] == 1 ? 2 : 1;
                
            if (!check(dislike, visit, group, map)) {
                return false;
            }
        }
        
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> group(N + 1, 0);
        vector<bool> visit(N + 1, false);
        unordered_map<int, vector<int>> map;
        
        for (int i = 0; i < dislikes.size(); ++i) {
            map[dislikes[i][0]].push_back(dislikes[i][1]);
            map[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        
        for (int i = 1; i <= N; ++i) {
            if (visit[i]) continue;
            if (!check(i, visit, group, map)) {
                return false;
            }
        }
        
        return true;
    }
};