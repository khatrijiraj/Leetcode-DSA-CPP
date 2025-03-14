class Solution {
private:
    bool check(vector<int>& candies, long long k, int mid) {
        long long count = 0;

        for (auto it : candies) {
            k -= it / mid;
            if (!k) {
                return true;
            }
        }

        return count >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int right = *max_element(candies.begin(), candies.end());
        int left = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(candies, k, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};