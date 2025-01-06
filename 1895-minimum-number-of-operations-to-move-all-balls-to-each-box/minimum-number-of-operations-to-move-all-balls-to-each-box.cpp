class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.length(), 0);
        for (int i = 0; i < boxes.length(); i++) {
            if (boxes[i] == '1') {
                for (int j = 0; j < boxes.length(); j++) {
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