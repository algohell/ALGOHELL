#include <vector>
#include <tuple>

using namespace std;

class Solution
{
public:
  // 키 내림차순 정렬. 키 같으면 앞에 있는 사람 수 오름차순으로 정렬
  // 키 같으면 앞에 있는 사람 수 큰게 나중에 들어가야 함
  static bool cmp(pair<int, int> a, pair<int, int> b)
  {
    if (a.first == b.first)
    {
      return b.second > a.second;
    }
    return b.first < a.first;
  }
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
  {
    sort(people.begin(), people.end(), cmp);
    vector<pair<int, int>> answer;
    for (int i = 0; i < people.size(); i++)
    {
      int curr = i; // i 번째에 먼저 넣는 다고 생각.
      while (curr > 0)
      {
        // i번째있는 사람의 앞에 있는 수가 현재 앞에 있는 사람 수 보다 크면
        // 앞으로 하나씩 떙겨준다.(키 내림차순으로 정렬했기 때문에 먼저 들어간 애들은
        // 지금 들어오는 얘의 영향을 받지 않음
        if (curr == people[i].second)
        {
          break;
        }
        else
        {
          curr--;
        }
      }
      answer.insert(answer.begin() + curr, people[i]);
    }
    return answer;
  }
};