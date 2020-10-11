class Solution
{
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    vector<int> ans;
    int closest = INT_MAX;
    int closestIdx = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
      int diff = abs(x - arr[i]);
      if (diff < closest)
      {
        closestIdx = i;
        closest = diff;
      }
    }

    int l = closestIdx, r = closestIdx + 1;

    while (ans.size() < k && (l >= 0 || r < arr.size()))
    {
      if (l < 0)
      {
        ans.push_back(arr[r]);
        ++r;
      }
      else if (r >= arr.size())
      {
        ans.push_back(arr[l]);
        --l;
      }
      else if (abs(x - arr[l]) > abs(x - arr[r]))
      {
        ans.push_back(arr[r]);
        ++r;
      }
      else
      {
        ans.push_back(arr[l]);
        --l;
      }
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};