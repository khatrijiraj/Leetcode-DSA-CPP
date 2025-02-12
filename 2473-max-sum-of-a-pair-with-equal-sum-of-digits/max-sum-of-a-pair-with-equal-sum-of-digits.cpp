class Solution {
public:
    typedef priority_queue<int> maxheap;
    int maximumSum(vector<int>& nums) {
        unordered_map<int, maxheap> mpp;

        for (auto it : nums) {
            int num = it;
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            mpp[sum].push(it);
        }

        int maxi = -1;

        for (auto [sum, heap] : mpp) {
            if (heap.size() < 2) {
                continue;
            }

            int top1 = heap.top();
            heap.pop();
            int top2 = heap.top();
            heap.pop();

            maxi = max(maxi, top1 + top2);
        }

        return maxi;
    }
};