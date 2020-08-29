class Solution
{
public:
  int gcd(int a, int b)
  {
    if (b == 0)
    {
      return a;
    }
    else
    {
      return gcd(b, a % b);
    }
  }
  vector<string> simplifiedFractions(int n)
  {
    vector<string> ans;

    for (int i = 2; i <= n; ++i)
    {
      for (int j = 1; j < i; ++j)
      {
        if (gcd(j, i) == 1)
        {
          ans.push_back(to_string(j) + "/" + to_string(i));
        }
      }
    }

    return ans;
  }
};