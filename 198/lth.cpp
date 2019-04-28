class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int curr[2] = {0, 0};
    int prev[2] = {0, 0};
    // 0 - 턴다. 1- 안턴다.
    for (auto num : nums)
    {
      int tempA = curr[0];
      int tempB = curr[1];
      curr[0] = max({curr[1], prev[0], prev[1]}) + num;
      curr[1] = max({tempA, tempB, prev[0], prev[1]});
    }
    return max({curr[0], curr[1], prev[0], prev[1]});
  }
};