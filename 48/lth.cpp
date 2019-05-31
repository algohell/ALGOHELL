class Solution
{
public:
  // len은 -2씩, curr은 +1씩 증감
  void rota(vector<vector<int>> &matrix, int curr, int len)
  {
    if (len <= 1)
    {
      return;
    }
    int cnt = len;
    int p = curr;
    int maxP = curr + len - 1;
    while (--cnt)
    {
      int x = p;
      int y = p;
      int prev = matrix[x][y];
      for (y; y < maxP; ++y)
      {
        swap(prev, matrix[x][y]);
      }
      for (x; x < maxP; ++x)
      {
        swap(prev, matrix[x][y]);
      }
      for (y; y > p; --y)
      {
        swap(prev, matrix[x][y]);
      }
      for (x; x > p; --x)
      {
        swap(prev, matrix[x][y]);
      }
      swap(prev, matrix[p][p]);
    }
    rota(matrix, curr + 1, len - 2);
  }
  void rotate(vector<vector<int>> &matrix)
  {
    int size = matrix.size();
    rota(matrix, 0, size);
  }
};