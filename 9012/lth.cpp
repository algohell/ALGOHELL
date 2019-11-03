#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool check(string s) {
  stack<char> st;
  for (char c : s) {
    if (c == '(') {
      st.push(c);
    }
    else {
      if (st.empty()) return false;
      st.pop();
    }
  }
  return st.empty();
}

int main() {
  string s;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    cout << (check(s) ? "YES" : "NO") <<endl;
  }
}