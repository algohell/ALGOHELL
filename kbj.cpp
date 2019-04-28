#include <priority_queue>
#include <vector>

using namespace std;

typedef pair<int, int> pr;

struct cmp
{
  bool operator()(pr a, pr b)
  {
    return a.second < b.second;
  }
};

class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    int interval = 0;
    int count = 0;
    bool isDone = false;

    vector<pr> v(26, {0, 0});

    for (auto t : tasks)
    {
      v[t - 'Z'] = {t - 'Z', v[t - 'Z'].second + 1};
    }

    priority_queue<pr, vector<pr>, cmp> p_queue;

    for (auto i : v)
    {
      p_queue.push(i);
    }

    while (p_queue.top().second == 0)
    {
      for (int i = 0; i < n; i++)
      {
        count++;
        pr tmp = p_queue.top();
        p_queue.pop();
        tmp.second--;
        p_queue.push(tmp);
      }
      count++;
    }

    return count;
  }
};