class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, start, mid, end);
    }

    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> leftnums(nums.begin() + start, nums.begin() + mid + 1);
        vector<int> rightnums(nums.begin() + mid + 1, nums.begin() + end + 1);

        int i = 0, j = 0, k = start;

        while (i < leftnums.size() && j < rightnums.size()) {
            if (leftnums[i] < rightnums[j]) {
                nums[k++] = leftnums[i++];
            } else {
                nums[k++] = rightnums[j++];
            }
        }

        while (i < leftnums.size()) {
            nums[k++] = leftnums[i++];
        }

        while (j < rightnums.size()) {
            nums[k++] = rightnums[j++];
        }
    }
};