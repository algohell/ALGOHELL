#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[20];
int cost[4];
int month[13];

int main()
{
  int t, cnt = 1;
  scanf("%d", &t);
  while (cnt <= t)
  {
    for (int i = 0; i < 4; ++i)
    {
      scanf("%d", &cost[i]);
    }
    for (int i = 0; i < 12; ++i)
    {
      scanf("%d", &month[i]);
    }
    for (int i = 11; i >= 0; --i)
    {
      int curr = min(cost[0] * month[i], cost[1]);
      dp[i] = min({dp[i + 3] + cost[2], dp[i + 1] + curr});
    }
    int minCost = min(dp[0], cost[3]);
    printf("#%d %d\n", cnt++, minCost);
  }
}