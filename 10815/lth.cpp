#include <stdio.h>
#include <set>

using namespace std;

int main() {
  int n,m, tmp;
  set<int> s;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &tmp);
    s.insert(tmp);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &tmp);
    printf("%d ", s.count(tmp) ? 1 : 0);
  }
}