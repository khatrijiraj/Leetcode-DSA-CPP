class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char ch : columnTitle) {
            result = (result * 26) + (ch - 'A' + 1);
        }
        return result;
    }
};