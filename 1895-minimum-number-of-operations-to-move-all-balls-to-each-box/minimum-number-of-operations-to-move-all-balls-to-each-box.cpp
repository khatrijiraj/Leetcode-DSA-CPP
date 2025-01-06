class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') {
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        continue;
                    }
                    result[j] += abs(i - j);
                }
            }
        }
        return result;
    }
};