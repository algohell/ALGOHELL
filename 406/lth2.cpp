class Solution
{
public:
  static bool compare(vector<int> f, vector<int> s)
  {
    if (f[0] == s[0])
    {
      return f[1] < s[1];
    }
    return f[0] > s[0];
  }
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
  {
    sort(people.begin(), people.end(), compare);

    vector<vector<int>> ans;

    for (vector<int> p : people)
    {
      ans.insert(ans.begin() + p[1], p);
    }

    return ans;
  }
};