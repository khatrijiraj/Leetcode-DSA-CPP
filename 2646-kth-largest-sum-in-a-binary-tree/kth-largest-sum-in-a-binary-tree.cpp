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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) {
            return -1;
        }

        queue<TreeNode*> qt;
        vector<long long> sums;

        qt.push(root);

        while (!qt.empty()) {
            int level = qt.size();
            long long sum = 0;

            for (int i = 0; i < level; i++) {
                TreeNode* current = qt.front();
                qt.pop();
                sum += current->val;

                if (current->left) {
                    qt.push(current->left);
                }

                if (current->right) {
                    qt.push(current->right);
                }
            }

            sums.push_back(sum);
        }

        if (sums.size() < k) {
            return -1;
        }

        /* for (auto it : sums) {
            cout << it << ", ";
        }
        cout << endl; */

        sort(sums.begin(), sums.end(), greater<long long>());

        /* for (auto it : sums) {
            cout << it << ", ";
        }
        cout << endl; */

        return sums[k - 1];
    }
};