class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int size = nums.size();
    vector<int> ans(size);
    ans[0] = 1;
    for (int i = 1; i < size; ++i)
    {
      ans[i] = ans[i - 1] * nums[i - 1];
    }
    int prod = 1;
    for (int i = size - 1; i >= 0; --i)
    {
      ans[i] = ans[i] * prod;
      prod *= nums[i];
    }
    return ans;
  }
};