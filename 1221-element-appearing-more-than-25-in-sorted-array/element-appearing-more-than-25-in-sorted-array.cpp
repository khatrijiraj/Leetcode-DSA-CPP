class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int val = 0.25 * arr.size();

        unordered_map<int, int> mpp;

        for (auto it : arr) {
            mpp[it]++;
        }

        for (auto it : mpp) {
            if (it.second > val) {
                return it.first;
            }
        }

        return -1;
    }
};