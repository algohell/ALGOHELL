#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> countBits(int num)
  {
    vector<int> ans(num + 1, 0);
    for (int i = 1; i < num + 1; i++)
    {
      if (i % 2 != 0)
      {
        ans[i] = ans[i / 2] + 1;
      }
      else
      {
        ans[i] = ans[i / 2];
      }
    }
    return ans;
  }
};