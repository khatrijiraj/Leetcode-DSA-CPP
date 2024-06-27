class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;

        for (int it : nums1) {
            count[it]++;
        }

        vector<int> intersect;

        for (int it : nums2) {
            if (count[it] > 0) {
                intersect.push_back(it);
                count[it] = 0;
            }
        }

        return intersect;
    }
};