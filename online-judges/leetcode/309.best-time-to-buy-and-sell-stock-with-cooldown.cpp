/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
    int rec(vector<int>& prices, vector<int>& dp, int i) {
        if (i >= prices.size()) {
            return 0;
        }

        int &profit = dp[i];
        if (profit != -1)
            return profit;

        profit = max(profit, rec(prices, dp, i + 1));
        for (int j = i + 1; j < prices.size(); j++) {
            profit = max(profit, prices[j] - prices[i] + rec(prices, dp, j + 2));
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), -1);
        return rec(prices, dp, 0);
    }
};
// @lc code=end

