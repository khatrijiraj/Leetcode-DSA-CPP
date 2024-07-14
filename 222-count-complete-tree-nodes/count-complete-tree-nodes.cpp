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
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lefth = getHeight(root->left);
        int righth = getHeight(root->right);

        if (lefth == righth) {
            return (1 << lefth) + countNodes(root->right);
        } else {
            return (1 << righth) + countNodes(root->left);
        }
    }

    int getHeight(TreeNode* node) {
        int ht = 0;

        while (node) {
            ht++;
            node = node->left;
        }
        return ht;
    }
};