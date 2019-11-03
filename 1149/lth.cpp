#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1001][3];
int dp[1001][3];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 0; i < 3; ++i) {
    dp[0][i] = arr[0][i];
  }
  for (int i = 1; i < n; ++i) {
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
  }
  printf("%d\n", min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));
}