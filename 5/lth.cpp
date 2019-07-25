class Solution
{
public:
  string longestPalindrome(string s)
  {
    int len = s.size();
    int st = 0, ml = 1;
    bool p[1000][1000] = {
        false,
    };
    for (int i = 0; i < len; ++i)
    {
      p[i][i] = true;
      if (i > 0 && s[i - 1] == s[i])
      {
        p[i - 1][i] = true;
        st = i - 1;
        ml = 2;
      }
    }
    for (int l = 3; l <= len; ++l)
    {
      for (int i = 0; i + l - 1 < len; ++i)
      {
        int j = i + l - 1;
        if (p[i + 1][j - 1] && s[i] == s[j])
        {
          p[i][j] = true;
          st = i;
          ml = l;
        }
      }
    }
    return s.substr(st, ml);
  }
};
