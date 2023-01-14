/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
class Solution {
    void rec(string& num, int& target, vector<string>& res, int pos, string exp, long cur, long prev) {
        if (pos == num.length() && cur == target) {
            res.push_back(exp);
            return;
        }

        for (int i = pos; i < num.length(); i++) {
            string nowst = num.substr(pos, i - pos + 1);
            long now = stol(nowst);
            if (nowst.length() != to_string(now).length())
                break;
            if (pos == 0) {
                rec(num, target, res, i + 1, nowst, now, now);
                continue;
            }
            rec(num, target, res, i + 1, exp+'+'+nowst, cur + now, now);
            rec(num, target, res, i + 1, exp+'-'+nowst, cur - now, -now);
            rec(num, target, res, i + 1, exp+'*'+nowst, cur - prev + prev * now, prev * now);
        }

        return;
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        rec(num, target, res, 0, "", 0, 0);
        return res;
    }
};
// @lc code=end
