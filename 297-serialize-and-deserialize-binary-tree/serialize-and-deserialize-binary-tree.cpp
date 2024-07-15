/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        queue<TreeNode*> qt;
        qt.push(root);

        stringstream sso;

        while (!qt.empty()) {
            TreeNode* node = qt.front();
            qt.pop();

            if (node) {
                sso << node->val << ",";
                qt.push(node->left);
                qt.push(node->right);
            } else {
                sso << "null,";
            }
        }

        string result = sso.str();
        result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        stringstream sso(data);
        string str;

        getline(sso, str, ',');

        if (str == "null") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> qt;
        qt.push(root);

        while (!qt.empty()) {
            TreeNode* node = qt.front();
            qt.pop();

            if (getline(sso, str, ',')) {
                if (str != "null" && !str.empty()) {
                    node->left = new TreeNode(stoi(str));
                    qt.push(node->left);
                }
            }

            if (getline(sso, str, ',')) {
                if (str != "null" && !str.empty()) {
                    node->right = new TreeNode(stoi(str));
                    qt.push(node->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));