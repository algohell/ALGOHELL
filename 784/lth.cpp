class Solution
{
public:
  void findPermutation(string S, int curr, vector<string> &ans)
  {
    if (curr >= S.size())
    {
      return;
    }

    if (islower(S[curr]) || isupper(S[curr]))
    {
      string ns = S;
      ns[curr] = islower(S[curr]) ? toupper(S[curr]) : tolower(S[curr]);
      ans.push_back(ns);
      findPermutation(ns, curr + 1, ans);
    }

    findPermutation(S, curr + 1, ans);
  }
  vector<string> letterCasePermutation(string S)
  {
    vector<string> ans;

    ans.push_back(S);
    findPermutation(S, 0, ans);

    return ans;
  }
};