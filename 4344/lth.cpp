#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main() {
  int t, n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    double sum = 0, cnt = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &v[i]);
      sum += v[i];
    }
    double avg = sum / n;
    for (int vi : v) {
      if (vi > avg) ++cnt;
    }
    printf("%.3f%%\n", cnt / n * 100);
  }
}