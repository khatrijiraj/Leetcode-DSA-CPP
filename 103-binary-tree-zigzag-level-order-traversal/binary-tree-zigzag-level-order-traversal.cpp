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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode*> qt;
        qt.push(root);

        bool leftToRight = true;

        while (!qt.empty()) {
            int size = qt.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i) {
                TreeNode* node = qt.front();
                qt.pop();

                int index;
                if (leftToRight) {
                    index = i;
                } else {
                    index = size - i - 1;
                }

                level[index] = node->val;

                if (node->left) {
                    qt.push(node->left);
                }

                if (node->right) {
                    qt.push(node->right);
                }
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};