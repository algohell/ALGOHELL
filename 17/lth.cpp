class Solution
{
public:
  static void find(vector<string> &ans, string &temp, string digits, int index)
  {
    if (index == digits.size())
    {
      ans.push_back(temp);
      return;
    }
    int digit = digits[index] - '0';
    int start = 'a';
    int len = (digit == 7 || digit == 9) ? 4 : 3;
    for (int i = 2; i < digit; ++i)
    {
      start += (i == 7 || i == 9) ? 4 : 3;
    }
    for (int i = start; i < start + len; ++i)
    {
      temp.push_back(i);
      find(ans, temp, digits, index + 1);
      temp.pop_back();
    }
    return;
  }
  vector<string> letterCombinations(string digits)
  {
    vector<string> ans;
    if (digits.size() == 0)
      return ans;
    string temp;
    find(ans, temp, digits, 0);
    return ans;
  }
};