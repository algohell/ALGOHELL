class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int size = prices.size();
    if (size == 0)
      return 0;
    vector<vector<int>> dp(size, vector<int>(3, 0));

    for (int i = 1; i < size; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        if (prices[j] < prices[i])
        {
          dp[i][2] = max(dp[i][2], dp[j][1] + prices[i] - prices[j]);
        }
      }
      dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
      if (i > 1)
      {
        dp[i][1] = max(dp[i - 2][2], dp[i - 2][0]);
      }
      dp[i][1] = max(dp[i][1], dp[i - 1][0]);
    }
    return max({dp[size - 1][0], dp[size - 1][1], dp[size - 1][2]});
  }
};