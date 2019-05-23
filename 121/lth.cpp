class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }
        return ans;
    }
};