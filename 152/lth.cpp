class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int maxP = INT_MIN, product = 1;
    int len = nums.size();
    // 음수의 개수가 짝수면 여기서 정답이 나옴. (0이 있을 경우 분기점이 됨.)
    for (int i = 0; i < len; i++)
    {
      maxP = max(product *= nums[i], maxP);
      if (nums[i] == 0)
        product = 1;
    }
    // 홀수면 여기서.
    product = 1;
    for (int i = len - 1; i >= 0; i--)
    {
      maxP = max(product *= nums[i], maxP);
      if (nums[i] == 0)
        product = 1;
    }

    return maxP;
  }
};