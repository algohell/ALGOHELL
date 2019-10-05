class Solution
{
public:
  int titleToNumber(string s)
  {
    int size = s.size();
    int num = 0;
    for (int i = size - 1; i >= 0; --i)
    {
      int n = s[i] - 'A' + 1;
      num += pow(26, size - i - 1) * n;
    }
    return num;
  }
};
