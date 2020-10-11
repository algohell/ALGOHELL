class Solution
{
public:
  int numRescueBoats(vector<int> &people, int limit)
  {
    sort(people.begin(), people.end());
    int ans = 0;

    int start = 0, end = people.size() - 1;

    while (start <= end)
    {
      if (people[end] + people[start] <= limit)
      {
        ++start;
      }
      end--;
      ++ans;
    }

    return ans;
  }
};