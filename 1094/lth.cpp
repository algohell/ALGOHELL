class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int pickup[1001] = {0,};
        int dropoff[1001] = {0,};
        int dest = -1;
        for (vector<int> trip: trips) {
            int num = trip[0];
            pickup[trip[1]] += num;
            dropoff[trip[2]] += num;
            dest = max(dest, trip[2]);
        }
        int count = 0;
        for (int i = 0; i <= dest; ++i) {
            count += pickup[i] - dropoff[i];
            if (count > capacity) return false;
        }
        return true;
    }
};