class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        /* vector<int> smaller;
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

        return result; */

        // without extra space solution
        int n = nums.size();
        vector<int> result(n);
        int i_less = 0;
        int j_bigg = n - 1;

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            if (nums[i] < pivot) {
                result[i_less] = nums[i];
                i_less++;
            }

            if (nums[j] > pivot) {
                result[j_bigg] = nums[j];
                j_bigg--;
            }
        }

        while (i_less <= j_bigg) {
            result[i_less] = pivot;
            i_less++;
        }
        
        return result;
    }
};