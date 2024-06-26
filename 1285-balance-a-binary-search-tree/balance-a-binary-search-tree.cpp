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
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedBST;

        inOrderTraverse(root, sortedBST);

        return BuildBalancedBST(sortedBST, 0, sortedBST.size() - 1);
    }

private:
    void inOrderTraverse(TreeNode* node, vector<int>& sortedBST) {
        if (!node) {
            return;
        }

        inOrderTraverse(node->left, sortedBST);
        sortedBST.push_back(node->val);
        inOrderTraverse(node->right, sortedBST);
    }

    TreeNode* BuildBalancedBST(vector<int>& sortedBST, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* newNode = new TreeNode(sortedBST[mid]);
        newNode->left = BuildBalancedBST(sortedBST, left, mid - 1);
        newNode->right = BuildBalancedBST(sortedBST, mid + 1, right);

        return newNode;
    }
};