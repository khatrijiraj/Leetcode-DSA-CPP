class TrieNode {
public:
    TrieNode* children[26];
    int count;
    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        count = 0;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            node->count++;
        }
    }

    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            int index = ch - 'a';
            node = node->children[index];
            score += node->count;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        for (const string& word : words) {
            trie.insert(word);
        }

        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }

        return result;
    }
};
