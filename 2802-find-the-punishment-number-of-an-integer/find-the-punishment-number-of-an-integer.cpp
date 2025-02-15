class Solution {
private:
    bool ispunishment(string square, int num, int i, int currSum) {
        if (i == square.length()) {
            return currSum == num;
        }

        if (currSum > num) {
            return false;
        }

        for (int j = i; j < square.length(); j++) {
            string left = square.substr(i, j - i + 1);

            int val = stoi(left);

            if (ispunishment(square, num, j + 1, currSum + val)) {
                return true;
            }
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int sum = 0;

        for (int num = 1; num <= n; num++) {
            int square = num * num;
            if (ispunishment(to_string(square), num, 0, 0)) {
                sum += square;
            }
        }

        return sum;
    }
};