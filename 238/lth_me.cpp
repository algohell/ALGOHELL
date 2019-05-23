class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    vector<int> left;
    vector<int> right;
    int size = nums.size();
    int l = 1;
    int r = 1;
    for (int i = 0; i < size; ++i)
    {
      left.push_back(l);
      right.push_back(r);
      l *= nums[i];
      r *= nums[size - 1 - i];
    }
    vector<int> ans;
    for (int i = 0; i < size; ++i)
    {
      ans.push_back(left[i] * right[size - 1 - i]);
    }
    return ans;
  }
};