/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (41.04%)
 * Total Accepted:    334.2K
 * Total Submissions: 814.4K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
#include <vector>

using namespace std;

class Solution
{
public:
    void visit(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        int xLen = grid[0].size();
        int yLen = grid.size();

        // 불가능한 인덱스라면 리턴
        if (x < 0 || y < 0)
            return;
        if (x == xLen || y == yLen)
            return;
        // 방문했다면 리턴
        if (visited[y][x])
            return;
        // 도달한곳이 바다라면 리턴
        if (grid[y][x] == '0')
            return;

        // 방문 플래그를 세워준다
        visited[y][x] = true;

        // 사방향으로 전진
        visit(x - 1, y, grid, visited);
        visit(x + 1, y, grid, visited);
        visit(x, y - 1, grid, visited);
        visit(x, y + 1, grid, visited);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        int yLen = grid.size();
        int xLen = grid[0].size();
        int island = 0;

        vector<vector<bool>> visited(yLen, vector<bool>(xLen, false));

        for (int i = 0; i < yLen; i++)
        {
            for (int j = 0; j < xLen; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    island++;
                    visit(j, i, grid, visited);
                }
            }
        }
        return island;
    }
};
