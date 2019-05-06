class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int a = nums[0];
    int b = nums[0];
    do
    {
      a = nums[a];
      b = nums[nums[b]];
    } while (a != b);

    int pt = nums[0];
    while (pt != a)
    {
      pt = nums[pt];
      a = nums[a];
    }
    return pt;
  }
};