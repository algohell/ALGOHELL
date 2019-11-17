#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int in[32001];

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> vc(n + 1);
  for (int i = 0; i < m; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    in[b]++;
    vc[a].push_back(b);
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i)
  {
    if (!in[i])
      q.push(i);
  }
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    printf("%d ", curr);
    for (int v : vc[curr])
    {
      if (--in[v] <= 0)
        q.push(v);
    }
  }
}