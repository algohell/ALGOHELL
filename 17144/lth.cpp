#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[51][51] = {0,};
int tmp[51][51] = {0,};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void diff(int R, int C) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      int cnt = 0;
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && nj >= 0 && ni < R && nj < C && arr[ni][nj] != -1) {
          ++cnt;
          tmp[ni][nj] += arr[i][j] / 5;
        }
      }
      if (cnt > 0) {
        arr[i][j] = arr[i][j] - (arr[i][j] / 5 * cnt) ;
      }
    }
  }
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      arr[i][j] += tmp[i][j];
    }
  }
}

void cleanTop(int r, int c, int R, int C) {
  int tmp = 0;
  for (int i = c + 1; i < C; ++i) {
    swap(tmp, arr[r][i]);
  }
  for (int i = r - 1; i >= 0; --i) {
    swap(tmp, arr[i][C - 1]);
  }
  for (int i = C - 2; i >= 0; --i) {
    swap(tmp, arr[0][i]);
  }
  for (int i = 1; i < r; ++i) {
    swap(tmp, arr[i][0]);
  }
}

void cleanBot(int r, int c, int R, int C) {
  int tmp = 0;
  for (int i = c + 1; i < C; ++i) {
    swap(tmp, arr[r][i]);
  }
  for (int i = r + 1; i < R; ++i) {
    swap(tmp, arr[i][C-1]);
  }
  for (int i = C - 2; i >= 0; --i) {
    swap(tmp, arr[R-1][i]);
  }
  for (int i = R-2; i > r; --i) {
    swap(tmp, arr[i][0]);
  }
}

int main() {
  int R, C, T;
  int botR, botC;
  scanf("%d %d %d", &R, &C, &T);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      scanf("%d", &arr[i][j]);
      if (arr[i][j] == -1) {
        botR = i;
        botC = j;
      }
    }
  }
  while(T--) {
    diff(R, C);
    cleanTop(botR-1, botC, R, C);
    cleanBot(botR, botC, R, C);
    for(int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        tmp[i][j] = 0;
      }
    }
  }
  int sum = 0;
  for(int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (arr[i][j] != -1) {
        sum += arr[i][j];
      }
    }
  }
  printf("%d\n", sum);
}