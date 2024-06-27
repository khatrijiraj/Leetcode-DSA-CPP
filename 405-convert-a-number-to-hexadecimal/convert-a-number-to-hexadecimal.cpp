class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        string hex = "";

        unsigned int numm = num;

        while (numm) {
            int remainder = numm % 16;
            char digit;
            if (remainder < 10) {
                digit = '0' + remainder;
            } else {
                digit = 'a' + (remainder - 10);
            }
            hex = digit + hex;
            numm /= 16;
        }

        return hex;
    }
};