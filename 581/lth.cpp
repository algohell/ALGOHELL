#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    vector<int> temp = nums;
    sort(temp.begin(), temp.end()); // nums를 복사한 후 정렬

    int start = 0, end = temp.size() - 1;
    bool findStart = false, findEnd = false;
    // 다른 부분이 나오면 start와 end에 넣어주고 둘 다 찾으면 반복 중지
    while (start < temp.size() && end >= 0)
    {
      if (!findStart && temp[start] == nums[start])
      {
        ++start;
      }
      else
      {
        findStart = true;
      }
      if (!findEnd && temp[end] == nums[end])
      {
        --end;
      }
      else
      {
        findEnd = true;
      }
      if (findStart && findEnd)
        break;
    }

    if (!findStart)
      return 0;
    return end - start + 1;
  }
};