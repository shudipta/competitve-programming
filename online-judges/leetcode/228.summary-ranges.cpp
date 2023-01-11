/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        int upper, k = 0;
        if (nums.empty())
            return res;
        else {
            res.push_back(to_string(nums[0]));
            upper = nums[0];
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (res[k].back() == '>')
                    res[k] += to_string(upper);
                res.push_back(to_string(nums[i]));
                k++;
            }
            else if (res[k].back() != '>')
                res[k] += "->";
            upper = nums[i];
        }
        if (res[k].back() == '>')
            res[k] += to_string(upper);

        return res;
    }
};
// @lc code=end

