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
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return NULL;
        }

        TreeNode* save = root->right;
        root->right = root->left;
        root->left = save;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};