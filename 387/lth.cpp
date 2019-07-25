class Solution
{
public:
  int firstUniqChar(string s)
  {
    int a[26] = {0};
    for (char c : s)
    {
      a[c - 'a']++;
    }
    for (int i = 0; i < s.size(); ++i)
    {
      if (a[s[i] - 'a'] == 1)
        return i;
    }
    return -1;
  }
};
