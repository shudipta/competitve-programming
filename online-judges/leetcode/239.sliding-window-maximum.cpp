/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> w;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k && !w.empty() && w.front() <= i - k)
                w.pop_front();
            while (!w.empty() && nums[w.back()] < nums[i])
                w.pop_back();
            w.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[w.front()]);
        }

        return res;
    }
};
// @lc code=end

