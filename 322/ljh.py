class Solution:
    def coinChange(self, coins, amount):
      clen = len(coins)
      if amount == 0:
        return 0

      dp = [0] + [0 for _ in range(amount)]
      for i in range(clen):
        if coins[i] <= amount:
          dp[coins[i]] = 1
        for j in range(coins[i],amount+1):
          if dp[j] == 0:
            if dp[j-coins[i]] == 0:
              dp[j] = 0
            else:
              dp[j] = dp[j-coins[i]] + 1
          else:
            if dp[j-coins[i]] != 0:
              dp[j] = min(dp[j],dp[j-coins[i]]+1)
      if dp[amount] == 0:
        return -1
      return dp[amount]
      
coins = [5,2,1]
amount = 11
s = Solution()
print(s.coinChange(coins,amount))