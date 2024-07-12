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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int maxwidth = 0;
        queue<pair<TreeNode*, unsigned long long>> qt;
        qt.push({root, 0});

        while (!qt.empty()) {
            int size = qt.size();
            unsigned long long left = qt.front().second;
            unsigned long long right = qt.back().second;

            maxwidth = max(maxwidth, static_cast<int>(right - left + 1));

            for (int i = 0; i < size; i++) {
                auto [node, index] = qt.front();
                qt.pop();

                if (node->left) {
                    qt.push({node->left, 2 * index});
                }

                if (node->right) {
                    qt.push({node->right, 2 * index + 1});
                }
            }
        }

        return maxwidth;
    }
};