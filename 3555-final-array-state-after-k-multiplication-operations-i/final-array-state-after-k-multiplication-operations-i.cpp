class Solution {
public:
    typedef pair<int, int> p;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<p, vector<p>, greater<p>> minheap;

        for (int i = 0; i < nums.size(); i++) {
            minheap.push({nums[i], i}); //nlogn
        }

        while (k--) { //klogn
            auto [ele, idx] = minheap.top();
            minheap.pop();

            ele *= multiplier;
            nums[idx] = ele;

            minheap.push({ele, idx});
        }

        return nums;
        // nlogn + klogn
    }
};