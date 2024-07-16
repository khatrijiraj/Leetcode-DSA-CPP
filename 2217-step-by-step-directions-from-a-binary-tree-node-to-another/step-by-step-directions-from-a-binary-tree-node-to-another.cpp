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
    bool findPath(TreeNode* node, int& target, string& path) {
        if (!node) {
            return false;
        }

        if (node->val == target) {
            return true;
        }

        path.push_back('L');
        if (findPath(node->left, target, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(node->right, target, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc = "";
        string rootToDst = "";

        findPath(root, startValue, rootToSrc);
        findPath(root, destValue, rootToDst);

        int i = 0;
        while (i < rootToSrc.length() && i < rootToDst.length() &&
               rootToSrc[i] == rootToDst[i]) {
            i++;
        }

        string result = "";
        for (int j = i; j < rootToSrc.length(); j++) {
            result.push_back('U');
        }

        for (int j = i; j < rootToDst.length(); j++) {
            result.push_back(rootToDst[j]);
        }

        return result;
    }
};