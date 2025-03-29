class Solution {
public:
    const int MOD_CONST = 1e9 + 7;

    long long modExp(long long base, long long exp) {
        if (exp == 0)
            return 1;
        long long halfPower = modExp(base, exp / 2);
        long long result = (halfPower * halfPower) % MOD_CONST;
        if (exp % 2 == 1) {
            result = (result * base) % MOD_CONST;
        }
        return result;
    }

    vector<int> generatePrimes(int upperLimit) {
        vector<bool> isPrime(upperLimit + 1, true);
        vector<int> primeList;

        for (int i = 2; i * i <= upperLimit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= upperLimit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= upperLimit; i++) {
            if (isPrime[i]) {
                primeList.push_back(i);
            }
        }

        return primeList;
    }

    vector<int> calculatePrimeFactorsCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeFactorCounts(n, 0);

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> primes = generatePrimes(maxVal); // O(mloglogm)

        for (int i = 0; i < n; i++) { // O(n * log(m))
            int num = nums[i];

            for (int prime : primes) {
                if (prime * prime > num) {
                    break;
                }

                if (num % prime != 0) {
                    continue;
                }

                primeFactorCounts[i]++;
                while (num % prime == 0) {
                    num /= prime;
                }
            }
            if (num > 1) { // example: 15 -> prime factors 3, 5
                primeFactorCounts[i]++;
            }
        }

        return primeFactorCounts;
    }

    vector<int> calculateNextLarger(vector<int>& primeFactorCounts) {
        int n = primeFactorCounts.size();
        vector<int> nextLarger(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   primeFactorCounts[st.top()] <= primeFactorCounts[i]) {
                st.pop();
            }

            nextLarger[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nextLarger;
    }

    vector<int> calculatePrevLarger(vector<int>& primeFactorCounts) {
        int n = primeFactorCounts.size();
        vector<int> prevLarger(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   primeFactorCounts[st.top()] < primeFactorCounts[i]) {
                st.pop();
            }

            prevLarger[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prevLarger;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeFactorCounts =
            calculatePrimeFactorsCount(nums); // O(mloglogm + n*log(m))
        vector<int> nextLarger = calculateNextLarger(primeFactorCounts); // O(n)
        vector<int> prevLarger = calculatePrevLarger(primeFactorCounts); // O(n)

        int n = nums.size();
        vector<long long> subarrayLengths(n, 0);

        for (int i = 0; i < n; i++) { // O(n)
            subarrayLengths[i] =
                (long long)(nextLarger[i] - i) * (i - prevLarger[i]);
        }

        vector<pair<int, int>> sortedArr(n);
        for (int i = 0; i < n; i++) {
            sortedArr[i] = {nums[i], i};
        }

        sort(sortedArr.begin(), sortedArr.end(), greater<>()); // O(nlogn)

        long long result = 1;
        int index = 0;  // Start from the largest element greedily
        while (k > 0) { // O(k * log(operations))
            auto [num, i] = sortedArr[index];

            long long availableOperations =
                min((long long)k, subarrayLengths[i]);

            result = (result * modExp(num, availableOperations)) % MOD_CONST;

            k -= availableOperations;
            index++;
        }

        return result;
    }
};
