#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10001];
int dp[10001][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  dp[0][1] = arr[0];
  dp[1][0] = arr[0];
  dp[1][1] = arr[0] + arr[1];

  for (int i = 2; i < n; ++i) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    dp[i][1] = max(dp[i-1][0], dp[i-2][0] + arr[i-1]) + arr[i];
  }

  printf("%d\n", max(dp[n-1][1], dp[n-1][0]));
}