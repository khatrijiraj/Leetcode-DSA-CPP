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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        queue<TreeNode*> qt;
        qt.push(root);
        int level = 0;

        while (!qt.empty()) {
            int size = qt.size();
            vector<TreeNode*> nodesAtCurrentLevel;

            for (int i = 0; i < size; i++) {
                TreeNode* node = qt.front();
                qt.pop();
                
                nodesAtCurrentLevel.push_back(node);
                if (node->left) {
                    qt.push(node->left);
                }
                if (node->right) {
                    qt.push(node->right);
                }
            }

            if (level % 2 == 1) {
                int left = 0, right = nodesAtCurrentLevel.size() - 1;
                while (left < right) {
                    swap(nodesAtCurrentLevel[left]->val,
                         nodesAtCurrentLevel[right]->val);
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;
    }
};