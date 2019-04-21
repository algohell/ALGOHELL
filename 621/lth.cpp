class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    int ans = 0;
    priority_queue<int> q;
    vector<int> cnt(26, 0);
    for (char task : tasks)
    {
      cnt[task - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
      if (cnt[i] != 0)
        q.push(cnt[i]);
    }
    while (!q.empty())
    {
      vector<int> temp;
      int time = 0;
      for (int i = 0; i <= n; i++)
      {
        if (q.empty())
          break;
        ++time;
        int next = q.top();
        q.pop();
        temp.push_back(next - 1);
      }
      for (int val : temp)
      {
        if (val > 0)
        {
          q.push(val);
        }
      }
      ans += q.empty() ? time : n + 1;
    }
    return ans;
  }
};