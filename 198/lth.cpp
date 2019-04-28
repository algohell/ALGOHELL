class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int curr[2] = {0, 0};
    for (auto num : nums)
    {
      int tempA = curr[0];
      int tempB = curr[1];
      curr[0] = curr[1] + num;
      curr[1] = max(tempA, tempB);
    }
    return max(curr[0], curr[1]);
  }
};