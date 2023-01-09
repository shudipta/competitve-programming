/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        long res = 0, sign = 1, cur = 0;
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                cur = 10 * cur + s[i] - '0';
            }
            else if (s[i] == '-') {
                res += sign*cur;
                cur = 0;
                sign = -1;
            }
            else if (s[i] == '+') {
                res += sign*cur;
                cur = 0;
                sign = 1;
            }
            else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                cur = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                res += sign*cur;
                cur = 0;
                sign = 1;
                int st_sign = st.top(); st.pop();
                int st_cur = st.top(); st.pop();
                res = st_cur + st_sign * res;
            }
        }
        res += sign*cur;
        return res;
    }
};
// @lc code=end
