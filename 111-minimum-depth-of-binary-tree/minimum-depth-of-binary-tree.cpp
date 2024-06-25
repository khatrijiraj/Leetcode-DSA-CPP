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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        std::queue<std::pair<TreeNode*, int>> que;

        que.push({root,1});

        while(!que.empty()){
            TreeNode* node = que.front().first;
            int depth = que.front().second;
            que.pop();

            if(!node->left && !node->right){
                return depth;
            }

            if(node->left){
                que.push({node->left, depth + 1});
            }

            if(node->right){
                que.push({node->right, depth + 1});
            }
        }

        return 0;
    }
};