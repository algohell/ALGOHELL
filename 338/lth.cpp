#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> countBits(int num)
  {
    vector<int> bits;
    bits.push_back(0);
    if (num == 0)
      return bits;
    bits.push_back(1);
    int nextS = 2;
    for (int i = 2; i <= num; i++)
    {
      // 제곱수가 나오면 무조건 1임
      if (i == nextS)
      {
        bits.push_back(1);
        nextS *= 2;
      }
      else
      {
        // 제곱수가 아니면 가장 최근 제곱수의 1의 수 + 현재 수 - 가장 최근 제곱수의 1의 수
        int prevS = nextS / 2;
        bits.push_back(bits[prevS] + bits[i - prevS]);
      }
    }
    return bits;
  }
};