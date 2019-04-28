class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    int size = coins.size();
    vector<int> dp(amount + 1, 987654321);
    if (amount == 0)
      return 0;
    dp[0] = 0;
    for (int i = 0; i < size; ++i)
    {
      int curr = coins[i];
      for (int j = coins[i]; j <= amount; ++j)
      {
        // d[j] = j만큼 돈 사용했을 때 최소 동전 개수
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      }
    }
    if (dp[amount] != 987654321)
      return dp[amount];
    else
      return -1;
  }
};