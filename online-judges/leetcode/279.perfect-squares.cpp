/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
    int N;
    int dp[10005];

    int rec(int n) {
        if (dp[n] != 0) return dp[n];
        int root = sqrt(n);
        if (root * root == n) return dp[n] = 1;
        dp[n] = n;
        for (int i = 1; i * i <= n; i++) {
            dp[n] = min(dp[n], rec(i * i) + rec(n - i * i));
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        return rec(n);
    }
};
// @lc code=end

