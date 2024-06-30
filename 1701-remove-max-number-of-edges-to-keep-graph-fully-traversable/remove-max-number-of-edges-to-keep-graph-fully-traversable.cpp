class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 1), componentCount(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU == rootV) {
            return false;
        }
        
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        
        componentCount--;
        return true;
    }
    
    int getComponentCount() const {
        return componentCount;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int componentCount;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufAlice(n + 1);
        UnionFind ufBob(n + 1);
        
        int edgesUsed = 0;
        
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (ufAlice.unite(edge[1], edge[2])) {
                    ufBob.unite(edge[1], edge[2]);
                    edgesUsed++;
                }
            }
        }
        
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (ufAlice.unite(edge[1], edge[2])) {
                    edgesUsed++;
                }
            }
        }
        
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (ufBob.unite(edge[1], edge[2])) {
                    edgesUsed++;
                }
            }
        }
        
        if (ufAlice.getComponentCount() != 2 || ufBob.getComponentCount() != 2) {
            return -1;
        }
        
        return edges.size() - edgesUsed;
    }
};
