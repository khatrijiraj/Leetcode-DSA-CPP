/*
Problem statement
You are given two integers 'n', and 'm'.



Calculate 'gcd(n,m)', without using library functions.



Note:
The greatest common divisor (gcd) of two numbers 'n' and 'm' is the largest
positive number that divides both 'n' and 'm' without leaving a remainder.


Example:
Input: 'n' = 6, 'm' = 4

Output: 2

Explanation:
Here, gcd(4,6) = 2, because 2 is the largest positive integer that divides both
4 and 6.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
9 6


Sample Output 1:
3


Explanation of sample output 1:
gcd(6,9) is 3, as 3 is the largest positive integer that divides both 6 and 9.

Sample Input 2:
2 5


Sample Output 2:
1


Expected Time Complexity:
Try to solve this in O(log(n))


Constraints:
0 <= ‘n’ <= 10^5

Time Limit: 1 sec
 */

#include <bits/stdc++.h>
using namespace std;

// time complexity O(n)
int GCDorHCF_BruteForce(int num1, int num2) {
    int gcd;
    for (int i = 1; i <= min(num1, num2); i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

// time complexity O(log n)
/* Euclidean theorem: Gcd is the greatest number which is divided by
   both a and b.If a number is divided by both a and b, it is should be divided
   by (a-b) and b as well.
 */

int GCDorHCF_Optimal(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return GCDorHCF_Optimal(num2, num1 % num2);
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << GCDorHCF_BruteForce(num1, num2) << endl;
    cout << GCDorHCF_Optimal(num1, num2) << endl;
    return 0;
}