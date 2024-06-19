class Solution {
private:
    bool canWeMakeBouquet(int mid, vector<int>& bloomDay, int m, int k) {
        int bouquet = 0;
        int flowers = 0;

        for (int bloomed : bloomDay) {
            if (bloomed <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquet++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquet >= m;
    }

public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();

        if (static_cast<long long>(m) * k > size) {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canWeMakeBouquet(mid, bloomDay, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};