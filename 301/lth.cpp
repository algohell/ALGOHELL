class Solution
{
public:
  void backtrack(int pair, int idx, int rL, int rR, string origin, string s, unordered_set<string> &ans)
  {
    if (idx == origin.size())
    {
      if (pair == 0 && rL == 0 && rR == 0)
      {
        ans.insert(s);
      }
    }
    else
    {
      char curr = origin[idx];
      if (curr == '(')
      {
        if (rL)
        {
          backtrack(pair, idx + 1, rL - 1, rR, origin, s, ans);
        }
        backtrack(pair + 1, idx + 1, rL, rR, origin, s + curr, ans);
      }
      else if (curr == ')')
      {
        if (rR)
        {
          backtrack(pair, idx + 1, rL, rR - 1, origin, s, ans);
        }
        if (pair > 0)
        {
          backtrack(pair - 1, idx + 1, rL, rR, origin, s + curr, ans);
        }
      }
      else
      {
        backtrack(pair, idx + 1, rL, rR, origin, s + curr, ans);
      }
    }
  }
  vector<string> removeInvalidParentheses(string s)
  {
    int rL = 0, rR = 0;
    unordered_set<string> ans;
    for (char c : s)
    {
      if (c == '(')
      {
        ++rL;
      }
      else if (c == ')')
      {
        if (rL > 0)
          --rL;
        else
          ++rR;
      }
    }
    this->backtrack(0, 0, rL, rR, s, "", ans);
    return vector<string>(ans.begin(), ans.end());
  }
};