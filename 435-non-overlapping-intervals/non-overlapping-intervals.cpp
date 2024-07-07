class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int nonoverlap = 1;
        int last = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= last) {
                nonoverlap++;
                last = intervals[i][1];
            }
        }
        //[[1,2],[2,3],[3,4],[1,3]]
        // [[1,2],[2,3],[1,3],[3,4]]
        return intervals.size() - nonoverlap;
    }
};