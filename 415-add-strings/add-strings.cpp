class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int carry = 0;
        string result = "";

        while (n1 >= 0 || n2 >= 0 || carry != 0) {
            int digit1 = 0;
            int digit2 = 0;

            if (n1 >= 0) {
                digit1 = num1[n1] - '0';
                n1--;
            }

            if (n2 >= 0) {
                digit2 = num2[n2] - '0';
                n2--;
            }

            int sum = digit1 + digit2 + carry;

            carry = sum / 10;

            int digit = sum % 10;

            result += (digit + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};