class Solution {
public:
    void updST(int i, int l, int r, int upIdx, vector<long long>& segTree) {
        if (l == r) {
            segTree[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        if (upIdx <= mid) {
            updST(2 * i + 1, l, mid, upIdx, segTree);
        } else {
            updST(2 * i + 2, mid + 1, r, upIdx, segTree);
        }

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    long long querySegTree(int qstart, int qend, int i, int l, int r,
                           vector<long long>& segTree) {
        if (r < qstart || l > qend) {
            return 0;
        }

        if (l >= qstart && r <= qend) {
            return segTree[i];
        }

        int mid = l + (r - l) / 2;
        long long left = querySegTree(qstart, qend, 2 * i + 1, l, mid, segTree);
        long long right =
            querySegTree(qstart, qend, 2 * i + 2, mid + 1, r, segTree);
        return left + right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums2[i]] = i;
        }

        vector<long long> segTree(4 * n); // 0indexing segmetn tree
        long long result = 0;

        // Update with first mapped from nums2
        updST(0, 0, n - 1, mpp[nums1[0]], segTree);

        for (int i = 1; i < n; i++) {
            int idx = mpp[nums1[i]];
            long long left = querySegTree(0, idx, 0, 0, n - 1, segTree);
            long long notleft = i - left;
            long long afteridx2 = (n - 1) - idx;
            long long rigth = afteridx2 - notleft;
            result += left * rigth;

            updST(0, 0, n - 1, idx, segTree);
        }

        return result;
    }
};