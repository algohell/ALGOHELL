#include <minmax.h>

using namespace std;

class Solution
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.size() == 0)
      return 0;
    int prev = 0;
    int curr = nums[0];
    int tmp1, tmp2;
    for (int i = 1; i < nums.size(); i++)
    {
      tmp1 = max(prev + nums[i], curr);
      tmp2 = max(prev, curr);
      prev = tmp2;
      curr = tmp1;
    }
    return max(prev, curr);
  }
};