#include <vector>

using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int size = nums.size();
    vector<bool> dp(size, false); // 갈 수 있는지 없는지 저장
    dp[0] = true;
    int prev = -1; // 현재까지 포함되는 범위를 저장
    for (int i = 0; i < size - 1; i++)
    {
      if (!dp[i])
        continue; // 갈 수 없으면 다음으로
      if (prev >= i + nums[i])
        continue;
      prev = i + nums[i];
      int maxJ = min(i + nums[i], size - 1); // 최대 갈 수 있는 거리
      for (int j = i; j <= maxJ; j++)
      { // i부터 i + jump 까지 true로 만들어줌
        if (!dp[j])
        {
          dp[j] = true;
        }
      }
    }
    return dp[size - 1];
  }
};