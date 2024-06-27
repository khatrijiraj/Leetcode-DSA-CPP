class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }

        if(num <= 2){
            return false;
        }

        int low = 2;
        int high = num/2;

        while (low <= high) {
            double mid = low + (high - low) / 2;
            double square = mid * mid;
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