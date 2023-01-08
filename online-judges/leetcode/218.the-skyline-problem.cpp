/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<pair<int, int>, int>> points;
        for (auto b : buildings) {
            points.push_back({{b[0], 0}, -b[2]});
            points.push_back({{b[1], 1}, b[2]});
        }
        sort(points.begin(), points.end());

        multiset<int> heights;
        vector<vector<int>> res;
        for (auto p : points) {
            if (p.first.second == 0) {
                heights.insert(p.second);
            }
            else {
                heights.erase(heights.find(-p.second));
            }
            if (!heights.empty()) {
                int h = -(*heights.begin());
                if (!res.empty() && res.back()[1] == h)
                    continue;
                res.push_back({p.first.first, h});
            }
            else
                res.push_back({p.first.first, 0});
        }

        return res;
    }
};
// @lc code=end
