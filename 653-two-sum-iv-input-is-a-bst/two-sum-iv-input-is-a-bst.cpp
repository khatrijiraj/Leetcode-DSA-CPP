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

class BSTiterator {
private:
    stack<TreeNode*> stk;
    bool reverse;

    void pushAll(TreeNode* node, bool reverse) {
        while (node) {
            stk.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTiterator(TreeNode* root, bool reverse) {
        this->reverse = reverse;
        pushAll(root, reverse);
    }

    int next() {
        TreeNode* temp = stk.top();
        stk.pop();

        if (reverse) {
            pushAll(temp->left, reverse);
        } else {
            pushAll(temp->right, reverse);
        }

        return temp->val;
    }

    bool hasNext() { return !stk.empty(); }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator leftItr(root, false);
        BSTiterator rightItr(root, true);

        int left = leftItr.next();
        int right = rightItr.next();

        while (left < right) {
            int sum = left + right;
            if (sum == k) {
                return true;
            } else if (sum > k) {
                if (rightItr.hasNext()) {
                    right = rightItr.next();
                } else {
                    break;
                }
            } else {
                if (leftItr.hasNext()) {
                    left = leftItr.next();
                } else {
                    break;
                }
            }
        }

        return false;
    }
};