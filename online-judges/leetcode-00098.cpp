class Solution {
    bool isValidValue(int val, long long minVal, long long maxVal) {
        return minVal < val && val < maxVal;
    }

    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr)
            return true;

        if (!isValidValue(root->val, minVal, maxVal))
            return false;

        if (root->left != nullptr && root->left->val >= root->val)
            return false;

        if (root->right != nullptr && root->right->val <= root->val)
            return false;

        return check(root->left, minVal, min(maxVal, 1ll*root->val)) && 
                check(root->right, max(minVal, 1ll*root->val), maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        long long bound = (1ll << 31) + 1;
        return check(root, -bound, bound - 1);
    }
};
