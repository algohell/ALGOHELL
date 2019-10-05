class Solution
{
  void part(string s, int size, int curr, vector<vector<bool>> &palin, vector<vector<string>> &ans, vector<string> &sv)
  {
    if (curr == size)
    {
      ans.push_back(sv);
      return;
    }
    for (int i = curr; i < size; ++i)
    {
      if (palin[curr][i])
      {
        sv.push_back(s.substr(curr, i - curr + 1));
        part(s, size, i + 1, palin, ans, sv);
        sv.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s)
  {
    int size = s.size();
    vector<vector<bool>> palin(size, vector<bool>(size, false));

    for (int i = 0; i < size; ++i)
    {
      palin[i][i] = true;
      if (i != 0 && s[i] == s[i - 1])
      {
        palin[i - 1][i] = true;
      }
    }
    for (int len = 3; len <= size; ++len)
    {
      for (int i = 0; i + len <= size; ++i)
      {
        int j = i + len - 1;
        if (palin[i + 1][j - 1] && s[i] == s[j])
        {
          palin[i][j] = true;
        }
      }
    }
    vector<vector<string>> ans;
    vector<string> sv;
    part(s, size, 0, palin, ans, sv);
    return ans;
  }
};
