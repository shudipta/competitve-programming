/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     string form_path_str(vector<int>& path) {
//         string st = "";
//         for (int i = 0; i < path.size(); i++) {
//             if(i)
//                 st += "->";
//             st += to_string(path[i]);
//         }

//         return st;
//     }
//     void dfs(TreeNode* cur, vector<string>& res, vector<int> path) {
//         if (cur == nullptr) {
//             return;
//         }

//         path.push_back(cur->val);
//         if (cur->left == nullptr && cur->right == nullptr)
//             res.push_back(form_path_str(path));
//         if (cur->left != nullptr)
//             dfs(cur->left, res, path);
//         if (cur->right != nullptr)
//             dfs(cur->right, res, path);
//         path.pop_back();

//         return;
//     }
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> res;
//         vector<int> path;
//         dfs(root, res, path);
//         return res;
//     }
// };
class Solution {
    string form_path_str(vector<int>& path) {
        string st = "";
        for (int i = 0; i < path.size(); i++) {
            if(i)
                st += "->";
            st += to_string(path[i]);
        }

        return st;
    }
    vector<string> dfs(TreeNode* cur, vector<int>& path) {
        if (cur == nullptr)
            return {};

        vector<string> res, res1;
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr)
            res = {form_path_str(path)};
        if (cur->left != nullptr)
            res = dfs(cur->left, path);
        if (cur->right != nullptr) {
            res1 = dfs(cur->right, path);
            res.insert(res.end(), res1.begin(), res1.end());
        }
        path.pop_back();

        return res;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        res = dfs(root, path);
        return res;
    }
};
// @lc code=end

