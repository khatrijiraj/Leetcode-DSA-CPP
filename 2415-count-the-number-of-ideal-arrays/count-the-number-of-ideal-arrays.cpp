const int MOD = 1e9 + 7;
const int MAX_NUM = 10010;
const int MAX_PRIME_CNT = 15;

int combinations[MAX_NUM + MAX_PRIME_CNT][MAX_PRIME_CNT + 1];
vector<int> primeCounts[MAX_NUM]; // list of prime exponents of i
int smallestPrime[MAX_NUM];

class Solution {
public:
    Solution() {
        // Only run setup once
        if (combinations[0][0]) {
            return;
        }

        // Sieve of Eratosthenes to find smallest prime factor for every number
        for (int i = 2; i < MAX_NUM; ++i) {
            if (smallestPrime[i] == 0) {
                for (int j = i; j < MAX_NUM; j += i) {
                    if (smallestPrime[j] == 0) {
                        smallestPrime[j] = i;
                    }
                }
            }
        }

        // Count prime factor exponents for each number
        for (int i = 2; i < MAX_NUM; ++i) {
            int num = i;
            while (num > 1) {
                int prime = smallestPrime[num];
                int count = 0;
                while (num % prime == 0) {
                    num /= prime;
                    count++;
                }
                primeCounts[i].push_back(count);
            }
        }

        // Precompute combinations (n choose k) using Pascal's triangle
        combinations[0][0] = 1;
        for (int i = 1; i < MAX_NUM + MAX_PRIME_CNT; ++i) {
            combinations[i][0] = 1;
            for (int j = 1; j <= std::min(i, MAX_PRIME_CNT); ++j) {
                combinations[i][j] =
                    (combinations[i - 1][j] + combinations[i - 1][j - 1]) % MOD;
            }
        }
    }

    int idealArrays(int n, int maxValue) {
        long long totalWays = 0;

        // Try every number from 1 to maxValue
        for (int value = 1; value <= maxValue; ++value) {
            long long ways = 1;

            // For each prime exponent in value, calculate how many ways to
            // spread it across n slots
            for (int exponent : primeCounts[value]) {
                ways = ways * combinations[n + exponent - 1][exponent] % MOD;
            }

            totalWays = (totalWays + ways) % MOD;
        }

        return totalWays;
    }
};
