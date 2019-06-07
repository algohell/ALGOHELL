class Solution
{
public:
  static double findEquation(string curr, string target, unordered_map<string, vector<pair<string, double>>> &map, unordered_map<string, int> &check)
  {
    if (curr == target)
    {
      return 1.0;
    }
    if (check[curr])
    {
      return -1;
    }
    check[curr] = 1;
    for (pair<string, double> next : map[curr])
    {
      double res = next.second * findEquation(next.first, target, map, check);
      if (res >= 0)
      {
        return res;
      }
    }
    return -1.0;
  }
  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
  {
    int size = equations.size();
    vector<double> ans;
    unordered_map<string, vector<pair<string, double>>> map;
    for (int i = 0; i < size; ++i)
    {
      vector<string> eq = equations[i];
      double val = values[i];
      map[eq[0]].push_back(make_pair(eq[1], val));
      map[eq[1]].push_back(make_pair(eq[0], 1.0 / val));
    }

    for (int i = 0; i < queries.size(); ++i)
    {
      unordered_map<string, int> check;
      if (map[queries[i][0]].size() == 0)
      {
        ans.push_back(-1.0);
      }
      else
      {
        ans.push_back(findEquation(queries[i][0], queries[i][1], map, check));
      }
    }
    return ans;
  }
};