class Solution
{
public:
  int minStartValue(vector<int> &nums)
  {
    int minVal = nums[0];
    int acc = 0;

    for (int num : nums)
    {
      acc += num;
      minVal = min(acc, minVal);
    }

    if (minVal >= 0)
      return 1;
    return -minVal + 1;
  }
};