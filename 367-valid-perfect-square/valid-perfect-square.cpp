class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    bool isPerfectSquare(int num) {
        if(num < 0){
            return false;
        }

        long low = 0;
        int high = num;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long square = mid * mid;
            if (square == num) {
                return true;
            } else if (square > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};