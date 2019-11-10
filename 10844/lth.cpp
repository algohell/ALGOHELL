#include <stdio.h>

using namespace std;

int MOD = 1000000000;
int dp[101][10];

int main() {
  int n;
  scanf("%d", &n);

  dp[1][0] = 0;
  for (int i = 1; i <= 9; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 0) dp[i][j] = dp[i-1][j+1];
      else if(j==9) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
      dp[i][j] %= MOD;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 9; i++) {
    ans += dp[n][i] % MOD;
  }
  printf("%lld\n", ans % MOD);
}