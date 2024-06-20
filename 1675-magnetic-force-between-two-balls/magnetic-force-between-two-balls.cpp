class Solution {

private:
    bool isPossible(vector<int>& position, int m, int mid) {
        int count = 1;
        int last = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= mid) {
                count++;
                last = position[i];
                if (count == m) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(position, m, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};