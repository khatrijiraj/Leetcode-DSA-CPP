/* Problem statement
Determine if a given string ‘S’ is a palindrome using recursion. Return a
Boolean value of true if it is a palindrome and false if it is not.

Note: You are not required to print anything, just implement the function.
Example: Input: s = "racecar" Output: true Explanation: "racecar" is a
palindrome. Detailed explanation ( Input/output format, Notes, Images ) Sample
Input 1: abbba Sample Output 1: true Explanation Of Sample Input 1 : “abbba” is
a palindrome Sample Input 2: abcd Sample Output 2: false Explanation Of Sample
Input 2 : “abcd” is not a palindrome. Constraints: 0 <= |S| <= 10^6 where |S|
represents the length of string S. */

#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i, string& str) {
    if (i >= str.size() / 2) {
        return true;
    }
    if (str[i] != str[str.size() - i - 1]) {
        return false;
    }
    palindrome(i + 1, str);
}

int main() {
    string str = "NITIN";
    cout << palindrome(0, str);
    return 0;
}