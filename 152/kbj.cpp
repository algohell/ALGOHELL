/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (28.92%)
 * Total Accepted:    201.6K
 * Total Submissions: 697.1K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
#include <vector>
#include <minmax.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;
        int prevPlus = INT_MIN;
        int prevMinus = INT_MIN;
        for (auto n : nums)
        {
            int tmpPlus = prevPlus;
            int tmpMinus = prevMinus;
            if (n > 0)
            {
                prevPlus = tmpPlus == INT_MIN ? n : max(n, tmpPlus * n);
                prevMinus = tmpMinus == INT_MIN ? INT_MIN : min(n, tmpMinus * n);
            }
            if (n == 0)
            {
                prevPlus = n;
                prevMinus = n;
            }
            if (n < 0)
            {
                prevPlus = tmpMinus == INT_MIN ? INT_MIN : tmpMinus * n;
                prevMinus = tmpPlus == INT_MIN ? n : min(n, tmpPlus * n);
            }
            ans = max(max(prevPlus, prevMinus), ans);
        }
        return ans;
    }
};
