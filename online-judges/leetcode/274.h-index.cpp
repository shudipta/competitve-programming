/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = 0, n = citations.size(); i < n; i++) {
            int h = n - i;
            if (citations[i] >= h && (i == 0 || (i > 0 && citations[i - 1] <= h)))
                return h;
        }
        return 0;
    }
};
// @lc code=end

