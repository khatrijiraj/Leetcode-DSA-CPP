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
private:
    TreeNode* delNodesHelper(TreeNode* node, vector<TreeNode*>& result,
                             unordered_set<int>& stt) {
        if (!node) {
            return nullptr;
        }

        node->left = delNodesHelper(node->left, result, stt);
        node->right = delNodesHelper(node->right, result, stt);

        if (stt.find(node->val) != stt.end()) {
            if (node->left) {
                result.push_back(node->left);
            }
            if (node->right) {
                result.push_back(node->right);
            }
            return nullptr;
        }
        return node;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> stt;

        for (int it : to_delete) {
            stt.insert(it);
        }

        if (root && stt.find(root->val) == stt.end()) {
            result.push_back(root);
        }

        delNodesHelper(root, result, stt);

        return result;
    }
};