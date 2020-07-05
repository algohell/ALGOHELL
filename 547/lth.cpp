class Solution {
public:
    void findCircle(int i, int size, unordered_map<int, vector<int>>& map, vector<bool>& visit) {
        for (int num: map[i]) {
            if (num >= 0 && num < size && !visit[num]) {
                visit[num] = true;
                findCircle(num, size, map, visit);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        unordered_map<int, vector<int>> map;
        vector<bool> visit(size, false);
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i != j && M[i][j] == 1) {
                    map[i].push_back(j);
                }
            }
        }
        
        int num = 0;
        
        for (int i = 0; i < size; ++i) {
            if (!visit[i]) {
                ++num;
                findCircle(i, size, map, visit);
            }
        }
        
        return num;
    }
};