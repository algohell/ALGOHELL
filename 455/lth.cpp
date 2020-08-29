class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    int gi = 0, gSize = g.size();
    int si = 0, sSize = s.size();
    int ans = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (gi < gSize)
    {
      while (si < sSize && g[gi] > s[si])
        ++si;

      if (si < sSize)
      {
        ++ans;
        ++si;
        ++gi;
      }
      else
        break;
    }

    return ans;
  }
};