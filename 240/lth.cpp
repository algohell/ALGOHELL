class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int r = 0, c = 0;
    int rm = matrix.size();
    int cm = rm > 0 ? matrix[0].size() : 0;
    if (rm == 0 || cm == 0)
      return false;
    while (r < rm)
    {
      if (r + 1 >= rm || matrix[r + 1][c] > target)
        break;
      ++r;
    }
    while (r >= 0)
    {
      while (c + 1 < cm && matrix[r][c + 1] <= target)
      {
        ++c;
      }
      if (matrix[r][c] == target)
        return true;
      --r;
    }
    return false;
  }
};
