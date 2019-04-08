#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int ans = nums[0];
    int sum = 0;
    for (auto num : nums)
    {
      // 이번 num을 더한게 0보다 작으면 무조건 새로시작하는게 좋다.
      if (sum + num < 0)
      {
        ans = max(ans, num); // 전부 음수일 때 처리
        sum = 0;
      }
      else
      {
        sum += num;
        ans = max(ans, sum);
      }
    }
    return ans;
  }
};