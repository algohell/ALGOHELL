class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &T)
  {
    int size = T.size();
    vector<int> ans(size);
    stack<pair<int, int>> s;
    for (int i = 0; i < size; ++i)
    {
      while (!s.empty())
      {
        pair<int, int> top = s.top();
        if (top.first < T[i])
        {
          ans[top.second] = i - top.second;
          s.pop();
        }
        else
          break;
      }
      s.push(make_pair(T[i], i));
    }
    while (!s.empty())
    {
      ans[s.top().second] = 0;
      s.pop();
    }
    return ans;
  }
};