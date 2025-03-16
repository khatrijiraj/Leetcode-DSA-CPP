class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int mini = *min_element(ranks.begin(), ranks.end());
        int maxi = *max_element(ranks.begin(), ranks.end());

        vector<int> freq(maxi + 1);

        for (auto r : ranks) {
            freq[r]++;
        }

        long long low = 1;
        long long high = 1LL * mini * cars * cars;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long repaired = 0;

            for (int i = 1; i <= maxi; i++) {
                repaired += freq[i] * (long long)sqrt(mid / (long long)i);
            }

            if (repaired >= cars) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};