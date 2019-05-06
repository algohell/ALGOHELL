class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int count = 1;
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
      if (prev == nums[i])
      {
        ++count;
        if (count > nums.size() / 2)
        {
          return nums[i];
        }
      }
      else
        count = 1;
      prev = nums[i];
    }
    return nums[0];
  }
};