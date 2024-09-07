/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* head, TreeNode* node) {
        if (!head) {
            return true;
        }

        if (!node) {
            return false;
        }

        if (head->val != node->val) {
            return false;
        }

        return dfs(head->next, node->left) || dfs(head->next, node->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) {
            return false;
        }
        
        if (dfs(head, root)) {
            return true;
        }

        return isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};