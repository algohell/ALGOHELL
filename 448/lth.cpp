class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    int size = nums.size();
    vector<bool> check(size, false);
    vector<int> ans;
    for (int num : nums)
    {
      check[num - 1] = true;
    }
    for (int i = 0; i < size; ++i)
    {
      if (!check[i])
      {
        ans.push_back(i + 1);
      }
    }
    return ans;
  }
};