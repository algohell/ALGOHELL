class Solution {
public:
    int climbStairs(int n) {
        int pp = 1, p = 1;
        if (n < 2) return n == 0 ? 0 : 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = p;
            p = pp + p;
            pp = tmp;
        }
        return p;
    }
};