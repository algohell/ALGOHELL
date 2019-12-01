#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[1001][1001] = {0,};
int dp[1001][1001] = {0,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int getMaxMove(int n, int r, int c) {
  dp[r][c] = 1;
  for (int i = 0; i < 4; ++i) {
    int nr = r + dx[i], nc = c + dy[i];
    if (nr >= n || nr < 0 || nc >= n || nc < 0) {
      continue;
    }
    if (arr[nr][nc] == arr[r][c] + 1) {
      int v = dp[nr][nc] != 0 ? dp[nr][nc] : getMaxMove(n, nr, nc);
      dp[r][c] = max(v + 1, dp[r][c]);
    }
  }
  return dp[r][c];
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int n, maxV = 0, maxRoom = 987654321;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &arr[i][j]);
        dp[i][j] = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int v = getMaxMove(n, i, j);
        if (v > maxV) {
          maxV = v;
          maxRoom = arr[i][j];
        }
        else if (v == maxV) {
          maxRoom = min(maxRoom, arr[i][j]);
        }
      }
    }
    printf("#%d %d %d\n", t, maxRoom, maxV);
  }
}