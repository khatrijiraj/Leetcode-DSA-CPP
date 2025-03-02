class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        /*  map<int, int> mpp;
         for (auto it : nums1) {
             mpp[it[0]] += it[1];
         }
         for (auto it : nums2) {
             mpp[it[0]] += it[1];
         }
         vector<vector<int>> result;
         for (auto it : mpp) {
             result.push_back({it.first, it.second});
         }
         return result; */

        int i = 0;
        int j = 0;
        vector<vector<int>> result;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i][0] == nums2[j][0]) {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                result.push_back({nums1[i][0], nums1[i][1]});
                i++;
            } else {
                result.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }

        while (i < nums1.size()) {
            result.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        while (j < nums2.size()) {
            result.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return result;
    }
};