/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (41.44%)
 * Total Accepted:    173K
 * Total Submissions: 417.3K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
#include <math.h>
#include <minmax.h>

class Solution
{
  public:
    static void find(int n, int count, int &ans)
    {
        if (n < 0)
        {
            return;
        }
        if (n == 0)
        {
            ans = min(ans, count);
            return;
        }
        // 최소 제곱값
        int next = (int)floorl(sqrt(n));

        for (int i = next; i >= 1; i--)
        {
            find(n - pow(i, 2), count + 1, ans);
        }
    }
    int numSquares(int n)
    {
        int ans = 99999999;
        find(n, 0, ans);
        return ans;
    }
};