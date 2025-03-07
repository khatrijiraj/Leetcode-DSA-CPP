class Solution {
    bool checkprime(int num) {
        if (num < 2) {
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
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (checkprime(i)) {
                primes.push_back(i);
            }
        }
        return primes;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        /* vector<int> primes = PrimeRange(left, right);

        int mini = INT_MAX;
        if (primes.size() < 2) {
            return {-1, -1};
        }

        int x = -1, y = -1;

        for (int i = 0; i < primes.size() - 1; i++) {
            int temp = primes[i + 1] - primes[i];
            if (temp < mini) {
                mini = temp;
                x = primes[i];
                y = primes[i + 1];
            }
        }

        return {x, y}; */

        int mini = INT_MAX;
        int x = -1;
        int y = -1;

        int prevprime = -1;

        for (int num = left; num <= right; num++) {
            if (checkprime(num)) {
                if (prevprime != -1) {
                    int diff = num - prevprime;
                    if (diff < mini) {
                        mini = diff;
                        x = prevprime;
                        y = num;
                    }
                }
                prevprime = num;
            }
        }

        return {x, y};
    }
};
