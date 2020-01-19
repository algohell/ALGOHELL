int arr[26];
bool check() {
    int cnt = 0;
    bool miss = false;
    for (int i = 0; i < 26; ++i) {
        if (arr[i] == 0) continue;
        if (cnt == 0) cnt = arr[i];
        if (cnt != arr[i]) {
            return false;
        }
    }
    return true;
}
// Complete the isValid function below.
string isValid(string s) {
    for (char c : s) {
        arr[c-'a']++;
    }
    if (check()) {
        return "YES";
    }
    for (char c : s) {
        arr[c-'a']--;
        if (check()) return "YES";
        arr[c-'a']++;
    }
    return "NO";
}