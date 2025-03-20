class DisjointSetUnion {
    vector<int> parent;
    vector<int> cost;

public:
    DisjointSetUnion(int n) {
        parent.resize(n);
        cost.resize(n, -1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_parent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void union_nodes(int node1, int node2) {
        int root1 = find_parent(node1);
        int root2 = find_parent(node2);

        if (root1 != root2) {
            parent[root2] = root1;
            cost[root1] &= cost[root2];
        }
    }

    void update_cost(int node, int w) {
        int root = find_parent(node);
        cost[root] &= w;
    }

    int get_cost(int node) { return cost[find_parent(node)]; }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        DisjointSetUnion dsu(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            int parent_u = dsu.find_parent(u);
            int parent_v = dsu.find_parent(v);

            if (parent_u != parent_v) {
                dsu.union_nodes(u, v);
            }

            dsu.update_cost(u, w);
            dsu.update_cost(v, w);
        }

        vector<int> result;
        for (auto it : queries) {
            int s = it[0];
            int e = it[1];

            int parent_s = dsu.find_parent(s);
            int parent_e = dsu.find_parent(e);

            if (s == e) {
                result.push_back(0);
            } else if (parent_s != parent_e) {
                result.push_back(-1);
            } else {
                result.push_back(dsu.get_cost(s));
            }
        }

        return result;
    }
};
