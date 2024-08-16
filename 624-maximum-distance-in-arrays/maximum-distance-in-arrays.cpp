class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();

        int maxidist = 0;

        for (int i = 1; i < arrays.size(); i++) {
            maxidist = max(maxidist, abs(arrays[i].back() - mini));
            maxidist = max(maxidist, abs(arrays[i][0] - maxi));

            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }

        return maxidist;
    }
};