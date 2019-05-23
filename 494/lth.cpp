class Solution
{
public:
  int find(vector<int> &nums, vector<int> &sums, int i, int S)
  {
    if (i == nums.size())
    {
      if (S == 0)
      {
        return 1;
      }
      else
        return 0;
    }
    int target = sums[nums.size() - 1] - (i > 0 ? sums[i - 1] : 0);
    int cnt = 0;
    if (target >= S)
    {
      cnt += find(nums, sums, i + 1, S + nums[i]) + find(nums, sums, i + 1, S - nums[i]);
    }
    return cnt;
  }
  int findTargetSumWays(vector<int> &nums, int S)
  {
    int size = nums.size();
    int sum = 0;
    vector<int> sums(size);
    sums[0] = nums[0];
    for (int i = 1; i < size; ++i)
    {
      sums[i] = sums[i - 1] + nums[i];
    }
    return find(nums, sums, 0, S);
  }
};