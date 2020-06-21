class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int step = cost.size();
        vector<int> dp(step, INT_MAX);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < step; ++i) {
            dp[i] = min({dp[i], dp[i - 1] + cost[i], dp[i - 2] + cost[i]});
        }
        
        return min(dp[step - 1], dp[step-2]);
    }
};