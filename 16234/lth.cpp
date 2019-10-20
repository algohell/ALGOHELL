#include <stdio.h>
#include <queue>
#include <tuple>

using namespace std;

int arr[51][51] = {0,};
int check[51][51] = {0,};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void uni(int r, int c, int N, int L, int R, int& u) {
    ++u;
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    check[r][c] = u;
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cr + dx[i], nc = cc + dy[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N && check[nr][nc] != u) {
                int sub = abs(arr[nr][nc] - arr[cr][cc]);
                if (sub >= L && sub <= R) {
                    q.push(make_pair(nr, nc));
                    check[nr][nc] = u;
                }
            }
        }
    }
}
void move(int u, int N) {
    int cnt[3000] = {0,};
    int total[3000] = {0,};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int idx = check[i][j];
            cnt[idx]++;
            total[idx] += arr[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int idx = check[i][j];
            if (cnt[idx] != 0) {
                arr[i][j] = total[idx] / cnt[idx];
            }
        }
    }
}

int main() {
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);

    for (int i = 0 ; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    int ans = 0;
    while (true) {
        int u = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                check[i][j] = 0;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (check[i][j] == 0) {
                    uni(i, j, N, L, R, u);
                }
            }
        }
        if (u == N * N) break;
        move(u, N);
        ++ans;
    }
    printf("%d\n" ,ans);
}