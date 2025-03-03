class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> bigger;
        int equal = 0;

        for (auto it : nums) {
            if (it < pivot) {
                smaller.push_back(it);
            } else if (it > pivot) {
                bigger.push_back(it);
            } else {
                equal++;
            }
        }

        vector<int> result;
        for (auto it : smaller) {
            result.push_back(it);
        }

        while (equal--) {
            result.push_back(pivot);
        }

        for (auto it : bigger) {
            result.push_back(it);
        }

        return result;
    }
};