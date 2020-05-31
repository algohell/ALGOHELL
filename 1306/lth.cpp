class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            if (arr[curr] == 0) {
                return true;
            }
            
            q.pop();
            
            int prev = curr - arr[curr];
            int next = curr + arr[curr];
            
            if (prev >= 0 && prev < arr.size() && !visited[prev]) {
                q.push(prev);
                visited[prev] = true;
            }
            if (next >= 0 && next < arr.size() && !visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
        
        return false;
    }
};
