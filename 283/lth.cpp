class Solution
{
public:
  static void swap(vector<int> &nums, int a, int b)
  {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
  }
  void moveZeroes(vector<int> &nums)
  {
    int left = 0;
    int right = 1;
    int size = nums.size();
    while (left < size && right < size)
    {
      if (nums[left] != 0)
      {
        ++left;
        ++right;
        continue;
      }
      while (right < size && nums[right] == 0)
      {
        ++right;
      }
      if (right >= size || left >= right)
        return;
      swap(nums, left, right);
      ++left;
    }
    return;
  }
};