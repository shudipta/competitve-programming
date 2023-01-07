/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
    int lps[100005];
    void genlps(string pat) {
        lps[0] = 0;
        for (int i = 1, l = 0; i < pat.length();) {
            if (pat[i] == pat[l]) {
                l++;
                lps[i] = l;
                i++;
            }
            else {
                if (l > 0) {
                    l = lps[l - 1];
                }
                else if (l == 0) {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return;
    }
public:
    string shortestPalindrome(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());
        genlps(s + "#" + revs);
        string extra = s.substr(lps[2 * s.length()]);
        reverse(extra.begin(), extra.end());
        return extra + s;
    }
};
// @lc code=end

