class Solution
{
  static bool can(int curr, vector<vector<int>> &pre, vector<bool> &check)
  {
    if (check[curr])
      return false;
    check[curr] = true;
    for (int i = 0; i < pre[curr].size(); ++i)
    {
      bool result = can(pre[curr][i], pre, check);
      if (!result)
      {
        check[curr] = false;
        return false;
      }
    }
    check[curr] = false;
    return true;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<vector<int>> pre(numCourses);
    vector<bool> check(numCourses, false);
    for (vector<int> vc : prerequisites)
    {
      pre[vc[0]].push_back(vc[1]);
    }

    for (int i = 0; i < numCourses; ++i)
    {
      if (!can(i, pre, check))
      {
        return false;
      }
    }
    return true;
  }
};
