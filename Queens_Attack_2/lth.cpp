#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int rowDx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int rowDy[8] = {1, -1, 0, 1, -1, 1, -1, 0};

int getCnt(int n, int r, int c, int dx, int dy, unordered_map<int, unordered_map<int, int>> obs) {
    int cnt = 0;
    r += dx;
    c += dy;
    while (r <= n && r >= 1 && c <= n && c >= 1) {
        if (obs[r][c]) {
            break;
        }
        ++cnt;
        r += dx;
        c += dy;
    }
    return cnt;
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    unordered_map<int, unordered_map<int, int>> obs;
    int cnt = 0;
    for (int i = 0; i < obstacles.size(); ++i) {
        int r = obstacles[i][0], c = obstacles[i][1];
        obs[r][c] = 1;
    }
    for (int i = 0; i < 8; ++i) {
        cnt += getCnt(n, r_q, c_q, rowDx[i], rowDy[i], obs);
    }
    return cnt;
}