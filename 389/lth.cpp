class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    int arr[26] = {
        0,
    };
    for (char c : s)
    {
      arr[c - 97]++;
    }
    for (char c : t)
    {
      arr[c - 97]--;
      if (arr[c - 97] < 0)
      {
        return c;
      }
    }

    return 'a';
  }
};