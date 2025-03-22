class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = findparent(parent[x]);
    }

    void unionnodes(int u, int v) {
        int up = findparent(u);
        int vp = findparent(v);

        if (up == vp) {
            return;
        }

        if (size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
        } else if (size[up] < size[vp]) {
            parent[up] = vp;
            size[vp] += size[up];
        } else {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        unordered_map<int, int> mpp;

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            dsu.unionnodes(u, v);
        }

        for (auto it : edges) {
            int u = it[0];
            int root = dsu.findparent(u);
            mpp[root]++;
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (dsu.findparent(i) == i) {
                int v = dsu.size[i];
                int e = mpp[i];

                if ((v * (v - 1)) / 2 == e){
                    result++;
                }
            }
        }

        return result;
    }
};