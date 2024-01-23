/* Problem statement
Check whether a given number ’n’ is a palindrome number.

Note :
Palindrome numbers are the numbers that don't change when reversed.
You don’t need to print anything. Just implement the given function.
Example:
Input: 'n' = 51415
Output: true
Explanation: On reversing, 51415 gives 51415.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
1032
Sample Output 1 :
false
Explanation Of Sample Input 1:
1032, on being reversed, gives 2301, which is a totally different number.
Sample Input 2 :
121
Sample Output 2 :
true
Explanation Of Sample Input 2:
121, on being reversed, gives 121, which is the same.
Expected time complexity:
The expected time complexity is O(log(n)).
Constraints :
1 <= n <= 10^9
Time Limit: 1 sec */

#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n) {
    int original = n;
    int reverse = 0;
    while (n) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    if (reverse == original)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin >> n;
    cout << palindrome(n);
    return 0;
}