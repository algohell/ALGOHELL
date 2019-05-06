/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <vector>

using namespace std;

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = NULL;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
