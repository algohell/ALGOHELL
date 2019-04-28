#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &T)
  {
    // 정답 초기화
    vector<int> res(T.size(), 0);
    stack<int> st;

    for (int i = T.size() - 1; i >= 0; --i)
    {
      // 스택이 비어있거나, 현재 보고있는 값이 더 클때까지 스택에서 꺼냄
      while (!st.empty() && T[i] >= T[st.top()])
        st.pop();
      // 1. 스택이 비어있다면 현재값보다 큰 것이 없으므로 0
      // 2. 스택이 차져있다면 현재값보다 큰 값이 남아있으므로 그 인덱스를 넣음
      res[i] = st.empty() ? 0 : st.top() - i;
      // 스택으로 현재 인덱스 삽입
      st.push(i);
    }
    return res;
  }
};