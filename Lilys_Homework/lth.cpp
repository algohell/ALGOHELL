int lilysHomework(vector<int> arr) {
    unordered_map<int, int> mapA;
    unordered_map<int, int> mapB;
    for (int i = 0; i < arr.size(); ++i) {
        mapA[arr[i]] = i;
        mapB[arr[i]] = i;
    }
    vector<int> tmp = arr;
    vector<int> ttmp = arr;
    sort(tmp.begin(), tmp.end());
    int cntA = 0, cntB = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (ttmp[i] != tmp[i]) {
            int x = ttmp[i];
            swap(ttmp[i], ttmp[mapA[tmp[i]]]);
            int t = mapB[ttmp[i]];
            mapA[x] = mapA[tmp[i]];
            mapB[tmp[i]] = t;
            ++cntA;
        }
    }
    reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != tmp[i]) {
            int x = arr[i];
            int t = mapB[arr[i]];
            swap(arr[i], arr[mapB[tmp[i]]]);
            mapB[x] = mapB[tmp[i]];
            mapB[tmp[i]] = t;
            ++cntB;
        }
    }
    return min(cntA, cntB);
}