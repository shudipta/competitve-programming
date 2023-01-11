/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
class Solution {
    int inorder(TreeNode* cur, int &cnt, int &k) {
        if (cur == nullptr)
            return -1;
        int val = inorder(cur->left, cnt, k);
        if (val != -1)
            return val;
        cnt++;
        if (cnt == k)
            return cur->val;
        val = inorder(cur->right, cnt, k);
        return val;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, cnt, k);
    }
};
// @lc code=end

