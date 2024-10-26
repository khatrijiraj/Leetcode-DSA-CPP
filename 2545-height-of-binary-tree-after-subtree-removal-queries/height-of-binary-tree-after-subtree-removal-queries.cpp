class Solution {
private:
    int helper(TreeNode* node, int height) {
        if (node == NULL) {
            return 0;
        }
        nodeId[node->val] = uniqueId;
        nodeHeight[uniqueId] = height;

        uniqueId++;

        int leftSize = helper(node->left, height + 1);
        int rightSize = helper(node->right, height + 1);

        subtreeSize[nodeId[node->val]] = 1 + leftSize + rightSize;

        return 1 + leftSize + rightSize;
    }

public:
    unordered_map<int, int> nodeId, nodeHeight, subtreeSize;
    int uniqueId = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;
        helper(root, 0);

        vector<int> maxLeft(uniqueId), maxRight(uniqueId);

        for (int i = 0; i < maxLeft.size(); i++) {
            maxLeft[i] = nodeHeight[i];
            if (i > 0) {
                maxLeft[i] = max(maxLeft[i - 1], maxLeft[i]);
            }
        }

        for (int i = maxRight.size() - 1; i >= 0; i--) {
            maxRight[i] = nodeHeight[i];
            if (i + 1 < maxRight.size()) {
                maxRight[i] = max(maxRight[i], maxRight[i + 1]);
            }
        }

        for (auto q : queries) {
            int startId = nodeId[q];
            int endId = startId + subtreeSize[startId] - 1;
            int maxHeight = 0;

            if (startId > 0) {
                maxHeight = max(maxHeight, maxLeft[startId - 1]);
            }

            if (endId + 1 < maxRight.size()) {
                maxHeight = max(maxHeight, maxRight[endId + 1]);
            }

            result.push_back(maxHeight);
        }

        return result;
    }
};
