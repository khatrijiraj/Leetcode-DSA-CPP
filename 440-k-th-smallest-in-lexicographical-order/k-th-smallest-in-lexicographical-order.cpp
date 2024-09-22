class Solution {
public:
    int count(long prefix, long n) {
        long current = prefix;
        long next = prefix + 1;
        int steps = 0;
        while (current <= n) {
            steps += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int current = 1;
        k--;
        while (k > 0) {
            int steps = count(current, n);
            if (steps <= k) {
                current++;
                k -= steps;
            } else {
                current *= 10;
                k--;
            }
        }
        return current;
    }
};
