/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string ser_node(TreeNode* cur) {
        if (cur == NULL) {
            return "null";
        }
        return to_string(cur->val);
    }

    TreeNode* deser_node(string cur) {
        if (cur == "null" || cur == "") {
            return NULL;
        }
        return new TreeNode(stoi(cur));
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            data += ser_node(cur) + ",";
            if (cur != NULL) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root;
        queue<TreeNode*> q;

        string val = "";
        int i = 0;
        while (data[i] != ',') val += data[i++];
        root = deser_node(val);
        if (root != NULL) {
            q.push(root);
        }

        TreeNode *child;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            val = "";
            bool left = false, right = false;
            for (i++; i < data.length(); i++) {
                if (data[i] == ',') {
                    child = deser_node(val);

                    if (!left) {
                        cur->left = child;
                        left = true;
                    }
                    else {
                        cur->right = child;
                        right = true;
                    }

                    if (child != NULL)
                        q.push(child);

                    val = "";
                    if (right) {
                        break;
                    }
                }
                else
                    val += data[i];
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

