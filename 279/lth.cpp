#include <vector>

using namespace std;

class Solution
{
public:
  int numSquares(int n)
  {
    vector<int> dp(n + 1, -1);
    // 일단 제곱수는 모두 1이 최소.
    for (int i = 1; i * i <= n; i++)
    {
      dp[i * i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
      // 무조건 제곱수가 들어가는 걸 이용(그래야 최소가 될 수 있음)
      // 제곱수의 비용(1) 과 제곱수를 뺀 것의 비용이 최소가 되는 값을 dp에 넣어줌.
      for (int j = 1; j * j < i; j++)
      {
        if (dp[i] == -1 || 1 + dp[i - j * j] < dp[i])
          dp[i] = 1 + dp[i - j * j];
      }
    }
    return dp[n];
  }
};