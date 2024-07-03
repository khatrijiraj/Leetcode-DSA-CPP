class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int last = INT_MIN;
        int chain = 0;

        for (auto it : pairs) {
            if (it[0] > last) {
                last = it[1];
                chain++;
            }
        }

        return chain;
    }
};