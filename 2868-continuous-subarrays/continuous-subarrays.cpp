class Solution {
public:
    typedef pair<int, int> p;
    long long continuousSubarrays(vector<int>& nums) {
        int i = 0;

        priority_queue<p> maxheap;
        priority_queue<p, vector<p>, greater<p>> minheap;

        long long count = 0;

        for (int j = 0; j < nums.size(); j++) {
            maxheap.push({nums[j], j});
            minheap.push({nums[j], j});

            while (maxheap.top().first - minheap.top().first > 2) {
                i++;

                while (!maxheap.empty() && maxheap.top().second < i) {
                    maxheap.pop();
                }

                while (!minheap.empty() && minheap.top().second < i) {
                    minheap.pop();
                }
            }

            count += (j - i + 1);
        }

        return count;
    }
};