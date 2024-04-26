class Solution {
public:
    bool findHours(vector<int>& piles, int h, int mid) {
        int hours = 0;
        for (int bananas : piles) {
            hours += (bananas + mid - 1) / mid;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (findHours(piles, h, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

static const auto __optimize__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();