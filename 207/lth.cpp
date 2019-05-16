class Solution
{
public:
  bool isPossible(vector<vector<int>> &courses, vector<bool> &possible, vector<bool> &check, int curr)
  {
    if (check[curr])
    {
      return false;
    }
    if (possible[curr])
      return true;
    possible[curr] = true;
    for (int next : courses[curr])
    {
      check[curr] = true;
      possible[curr] = possible[curr] && isPossible(courses, possible, check, next);
      if (!possible[curr])
      {
        check[curr] = false;
        return false;
      }
      check[curr] = false;
    }
    return possible[curr];
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<vector<int>> courses(numCourses);
    vector<bool> possible(numCourses);
    vector<bool> check(numCourses, false);
    for (vector<int> &pre : prerequisites)
    {
      courses[pre[0]].push_back(pre[1]);
    }
    for (vector<int> &pre : prerequisites)
    {
      if (!isPossible(courses, possible, check, pre[0]))
      {
        return false;
      }
    }
    return true;
  }
};