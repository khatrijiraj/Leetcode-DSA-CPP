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
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        TreeNode* current = root;

        while (current) {
            if (current->left) {
                TreeNode* rightmost = current->left;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }

                rightmost->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};