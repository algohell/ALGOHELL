#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int cost = 0;
    int size = c.size();
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    int start = 0, end = size - 1;
    if (k >= size) {
        return accumulate(c.begin(), c.end(), 0);
    }
    for (int i = 0; i < size; ++i) {
        cost += c[i] * (i / k + 1);
    }
    return cost;
}
