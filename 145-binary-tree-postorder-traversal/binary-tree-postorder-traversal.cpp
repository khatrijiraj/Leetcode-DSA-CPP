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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> result;

        if (!root) {
            return result;
        }

        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;

        stk1.push(root);

        while (!stk1.empty()) {
            root = stk1.top();
            stk2.push(root);
            stk1.pop();

            if (root->left) {
                stk1.push(root->left);
            }
            if (root->right) {
                stk1.push(root->right);
            }
        }

        while (!stk2.empty()) {
            result.push_back(stk2.top()->val);
            stk2.pop();
        }

        return result;
    }
};