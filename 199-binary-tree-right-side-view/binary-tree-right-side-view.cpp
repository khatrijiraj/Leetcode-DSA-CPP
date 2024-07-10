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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if(!root){
            return result;
        }

        queue<TreeNode*> qt;

        qt.push(root);

        while(!qt.empty()){
            int size = qt.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = qt.front();
                qt.pop();

                if(i==size-1){
                    result.push_back(node->val);
                }

                if(node->left){
                    qt.push(node->left);
                }
                if(node->right){
                    qt.push(node->right);
                }
            }
        }

        return result;
    }
};