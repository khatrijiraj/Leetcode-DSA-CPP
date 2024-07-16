/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

private:
    int minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left) {
            current = current->left;
        }

        return current->val;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            int mini = minValueNode(root->right);
            root->val = mini;

            root->right = deleteNode(root->right, mini);
        }

        return root;
    }
};