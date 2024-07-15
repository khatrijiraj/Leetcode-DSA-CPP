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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> childrens;

        for(auto it: descriptions){
            int parent = it[0];
            int child = it[1];
            bool left = it[2];

            if(mpp.find(parent) == mpp.end()){
                mpp[parent] = new TreeNode(parent);
            }

            if(mpp.find(child) == mpp.end()){
                mpp[child] = new TreeNode(child);
            }

            if(left){
                mpp[parent]->left = mpp[child];
            } else {
                mpp[parent]->right = mpp[child];
            }

            childrens.insert(child);
        }

        TreeNode* root = NULL;
        for(auto it : mpp){
            if(childrens.find(it.first) == childrens.end()){
                root = it.second;
            }
        }

        return root;
    }
};