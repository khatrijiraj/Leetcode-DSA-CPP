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
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        // Check if the left subtree is balanced
        bool leftBalanced = isBalanced(root->left);
        if (!leftBalanced) {
            return false;
        }
        // Check if the right subtree is balanced
        bool rightBalanced = isBalanced(root->right);
        if (!rightBalanced) {
            return false;
        }
        // Check if the current node is balanced
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        return true;
    }
};