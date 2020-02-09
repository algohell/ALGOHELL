class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        for (int i = 0; i < size; ++i) {
            int j, curr = 0;
            for (j = i; j < i + size; ++j) {
                curr += gas[j % size] - cost[j % size];
                if (curr < 0) break;
            }
            if (j == i + size) {
                return i;
            }
        }
        return -1;
    }
};
