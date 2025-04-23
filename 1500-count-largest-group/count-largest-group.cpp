class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, vector<int>> mpp;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            mpp[sum].push_back(i);
        }

        int largest = INT_MIN;
        for (auto it : mpp) {
            int size = it.second.size();
            largest = max(largest, size);
        }

        int count = 0;
        for (auto it : mpp) {
            if (it.second.size() == largest) {
                count++;
            }
        }

        return count;
    }
};