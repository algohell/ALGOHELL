class Solution
{
public:
  int comp(char c1, char c2)
  {
    if (c1 == c2)
      return 0;
    if (c1 < c2)
      return -1;
    return 1;
  }
  bool checkIfCanBreak(string s1, string s2)
  {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int check = 0;
    for (int i = 0; i < s1.size(); ++i)
    {
      int curr = comp(s1[i], s2[i]);
      if (curr != 0)
      {
        check = curr;
        break;
      }
    }

    for (int i = 0; i < s1.size(); ++i)
    {
      int curr = comp(s1[i], s2[i]);
      if (curr != 0 && curr != check)
      {
        return false;
      }
    }

    return true;
  }
};