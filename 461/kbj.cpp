/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ans = x ^ y;
        int count = 0;
        while (ans != 1 && ans != 0)
        {
            if (ans % 2 == 1)
                count++;
            ans = ans / 2;
        }
        if (ans == 1)
            count++;
        return count;
    }
};
