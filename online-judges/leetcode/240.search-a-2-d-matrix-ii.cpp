/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
// class Solution {
//     bool find(vector<int>& row, int target) {
//         int l = 0, h = row.size() - 1, m;
//         while (l <= h) {
//             m = (l + h) / 2;
//             if (target == row[m])
//                 return true;
//             else if (target < row[m])
//                 h = m - 1;
//             else
//                 l = m + 1;
//         }
//         return false;
//     }
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size(), m = matrix[0].size();
//         for (int i = 0; i < n; i++) {
//             if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
//                 if (find(matrix[i], target))
//                     return true;
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j > -1) {
            if (matrix[i][j] == target)
                return true;
            matrix[i][j] > target ? j-- : i++;
        }
        return false;
    }
};
// @lc code=end

