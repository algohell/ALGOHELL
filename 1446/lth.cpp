class Solution
{
public:
  int maxPower(string s)
  {
    int p = 1;
    int tmp = 0;
    char prev = s[0];

    for (char c : s)
    {
      if (c == prev)
      {
        ++tmp;
      }
      else
      {
        prev = c;
        p = max(p, tmp);
        tmp = 1;
      }
    }

    p = max(p, tmp);

    return p;
  }
};