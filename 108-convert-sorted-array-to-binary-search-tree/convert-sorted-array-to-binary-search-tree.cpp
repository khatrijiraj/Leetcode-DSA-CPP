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
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if(left > right){
            return nullptr;
        }

        int mid = left + (right - left)/2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, left, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, right);

        return node;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};