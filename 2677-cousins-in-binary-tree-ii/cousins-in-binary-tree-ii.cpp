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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        queue<TreeNode*> qt;
        qt.push(root);

        vector<int> levelsum;

        while (!qt.empty()) {
            int size = qt.size();
            int sum = 0;
            while (size--) {
                TreeNode* node = qt.front();
                qt.pop();

                sum += node->val;

                if (node->left) {
                    qt.push(node->left);
                }
                if (node->right) {
                    qt.push(node->right);
                }
            }
            levelsum.push_back(sum);
        }

        qt.push(root);
        root->val = 0;
        int childlevel = 1;

        while (!qt.empty()) {
            int size = qt.size();
            while (size--) {
                TreeNode* curr = qt.front();
                qt.pop();

                int siblingsum = 0;
                if (curr->left) {
                    siblingsum += curr->left->val;
                }
                if (curr->right) {
                    siblingsum += curr->right->val;
                }

                if (curr->left) {
                    curr->left->val = levelsum[childlevel] - siblingsum;
                    qt.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = levelsum[childlevel] - siblingsum;
                    qt.push(curr->right);
                }
            }
            childlevel++;
        }
        return root;
    }
};