/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing
x causes the value to go outside the signed 32-bit integer range [-231, 231 -
1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or
unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-231 <= x <= 231 - 1
 */

#include <climits>
#include <iostream>

using namespace std;

class Solution {
   public:
    int reverse(int x) {
        long reverse = 0;
        while (x) {
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }
        if (reverse > INT_MAX || reverse < INT_MIN) {
            return 0;
        } else {
            return int(reverse);
        }
    }
};

int main() {
    Solution solution;

    // Test cases
    int input1 = 123;
    int input2 = -123;
    int input3 = 120;

    int result1 = solution.reverse(input1);
    int result2 = solution.reverse(input2);
    int result3 = solution.reverse(input3);

    cout << "Original: " << input1 << ", Reversed: " << result1 << endl;
    cout << "Original: " << input2 << ", Reversed: " << result2 << endl;
    cout << "Original: " << input3 << ", Reversed: " << result3 << endl;

    return 0;
}
