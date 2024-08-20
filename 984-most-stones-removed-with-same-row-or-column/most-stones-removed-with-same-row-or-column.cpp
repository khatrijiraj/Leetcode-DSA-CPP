class DisjointSetUnion {
private:
    vector<int> rank, parent;

public:
    DisjointSetUnion(int size) {
        rank.resize(size, 0);
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (parent[node] != node) {
            parent[node] = findparent(parent[node]);
        }
        return parent[node];
    }

    void unionbyrank(int u, int v) {
        int parentofu = findparent(u);
        int parentofv = findparent(v);

        if (parentofu != parentofv) {
            if (rank[parentofu] > rank[parentofv]) {
                parent[parentofv] = parentofu;
            } else if (rank[parentofu] < rank[parentofv]) {
                parent[parentofu] = parentofv;
            } else {
                parent[parentofv] = parentofu;
                rank[parentofu]++;  // Fix: Increment the rank of `parentofu`
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSetUnion ds(20001);

        for (auto& it : stones) {
            int row = it[0];
            int col = it[1] + 10001;
            ds.unionbyrank(row, col);
        }

        unordered_set<int> uniqueroots;

        for (auto& it : stones) {
            int root = ds.findparent(it[0]);
            uniqueroots.insert(root);
        }

        return n - uniqueroots.size();
    }
};
