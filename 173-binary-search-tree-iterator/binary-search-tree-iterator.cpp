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
class BSTIterator {
private:
    void pushAllLeft(TreeNode* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* temp = stk.top();
        stk.pop();

        if (temp->right) {
            pushAllLeft(temp->right);
        }

        return temp->val;
    }

    bool hasNext() { return !stk.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */