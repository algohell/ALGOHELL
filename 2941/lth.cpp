#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> st = {
  "c=",
  "c-",
  "dz=",
  "d-",
  "lj",
  "nj",
  "s=",
  "z="
};

int main() {
  string s;
  cin>>s;
  int idx = 0, cnt = 0, size = s.size();
  while(idx < size) {
    if (idx + 2 < size && st.count(s.substr(idx, 3))) {
      idx += 3;
    }
    else if (idx + 1 < size && st.count(s.substr(idx, 2))) {
      idx += 2;
    }
    else {
      idx++;
    }
    ++cnt;
  }
  cout<<cnt<<endl;
}