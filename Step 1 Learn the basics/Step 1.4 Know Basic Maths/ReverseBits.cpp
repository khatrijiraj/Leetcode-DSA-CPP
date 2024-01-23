/*

Problem statement
There is a song concert going to happen in the city. The price of each ticket is
equal to the number obtained after reversing the bits of a given 32 bits
unsigned integer ‘n’.



Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
0
12
Sample Output 1:
 0
 805306368
Explanation For Sample Input 1 :
For the first test case :
Since the given number N = 0 is represented as 00000000000000000000000000000000
in its binary representation. So after reversing the bits, it will become
00000000000000000000000000000000 which is equal to 0 only. So the output is 0.



For the second test case :
Since the given number N = 12 is represented as 00000000000000000000000000001100
in its binary representation. So after reversing the bits, it will become
0110000000000000000000000000000, which is equal to 805306368 only. So the output
is 805306368. Sample Input 2 :
2
6
4
Sample Output 2 :
 1610612736
 536870912
Explanation For Sample Input 1 :
For the first test case :
Since the given number N = 6 is represented as 00000000000000000000000000000110
in its binary representation. So after reversing the bits, it will become
01100000000000000000000000000000, which is equal to 1610612736.


For the second test case :
Since the given number N = 4 is represented as 00000000000000000000000000000100
in its binary representation. So after reversing the bits, it will become
0010000000000000000000000000000, which is equal to 536870912 only. Expected time
complexity: The expected time complexity is O(log(n)). Constraints : 1 <= T <=
10 0 <= N <= 2^32

Time Limit: 1 sec
 */

#include <bits/stdc++.h>
using namespace std;

long reversebits(long n) {
    unsigned int reverse = 0;
    for (int i = 0; i < 32; i++) {
        reverse = reverse << 1;
        if (n & 1) {
            reverse = reverse | 1;
        }
        n = n >> 1;
    }
    return reverse;
}

int main() {
    long n;
    cin >> n;
    cout << reversebits(n);
    return 0;
}