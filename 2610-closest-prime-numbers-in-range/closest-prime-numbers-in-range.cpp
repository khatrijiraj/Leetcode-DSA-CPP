class Solution {
    bool checkprime(int num) {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> PrimeRange(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (checkprime(i)) {
                result.push_back(i);
            }
        }
        return result;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> result = PrimeRange(left, right);

        int mini = INT_MAX;
        if (result.size() < 2) {
            return {-1, -1};
        }

        int x = -1, y = -1;

        for (int i = 0; i < result.size() - 1; i++) {
            int temp = result[i + 1] - result[i];
            if (temp < mini) {
                mini = temp;
                x = result[i];
                y = result[i + 1];
            }
        }

        return {x, y};
    }
};
