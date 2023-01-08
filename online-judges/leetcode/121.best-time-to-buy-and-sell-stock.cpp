/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int numOfDay = prices.size();
        vector<int> buy(numOfDay), sell(numOfDay);

        buy[0] = prices[0];
        sell[numOfDay - 1] = prices[numOfDay - 1];

        for (int i = 1, j = numOfDay - 2; i < numOfDay; i++, j--) {
            buy[i] = min(buy[i - 1], prices[i]);
            sell[j] = max(sell[j + 1], prices[j]);
        }

        int res = 0;
        for (int i = 0; i < numOfDay - 1; i++) {
            res = max(res, sell[i + 1] - buy[i]);
        }

        return res;
    }
};
// @lc code=end

