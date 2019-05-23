class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<pair<string, int>> cop;
    for (int i = 0; i < strs.size(); ++i)
    {
      string a = strs[i];
      sort(a.begin(), a.end());
      cop.push_back(make_pair(a, i));
    }
    sort(cop.begin(), cop.end());
    vector<vector<string>> ans;
    vector<string> temp;
    string prev = cop[0].first;
    temp.push_back(strs[cop[0].second]);
    for (int i = 1; i < cop.size(); ++i)
    {
      if (prev != cop[i].first)
      {
        prev = cop[i].first;
        ans.push_back(temp);
        temp.clear();
        temp.push_back(strs[cop[i].second]);
      }
      else
      {
        temp.push_back(strs[cop[i].second]);
      }
    }
    if (!temp.empty())
      ans.push_back(temp);
    return ans;
  }
};