class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for (auto it : s) {
            temp += to_string((it - 'a') + 1);
        }

        int result;
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (auto it : temp) {
                sum += (it - '0');
            }
            temp = to_string(sum);
            result = sum;
        }
        return result;
    }
};