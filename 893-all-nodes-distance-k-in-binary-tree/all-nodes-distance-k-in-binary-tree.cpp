/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void parents(TreeNode* node, TreeNode* parent,
                 unordered_map<TreeNode*, TreeNode*>& mpp) {
        if (!node) {
            return;
        }
        mpp[node] = parent;
        parents(node->left, node, mpp);
        parents(node->right, node, mpp);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        parents(root, NULL, mpp);

        vector<int> result;

        queue<TreeNode*> qt;

        unordered_set<TreeNode*> visited;

        qt.push(target);
        visited.insert(target);

        int dist = 0;

        while (!qt.empty()) {
            if (dist == k) {
                while (!qt.empty()) {
                    result.push_back(qt.front()->val);
                    qt.pop();
                }
                return result;
            }

            int size = qt.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = qt.front();
                qt.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    qt.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right && visited.find(node->right) == visited.end()) {
                    qt.push(node->right);
                    visited.insert(node->right);
                }

                TreeNode* daddy = mpp[node];
                if (daddy && visited.find(daddy) == visited.end()) {
                    qt.push(daddy);
                    visited.insert(daddy);
                }
            }
            dist++;
        }

        return result;
    }
};