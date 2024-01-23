/* Problem statement
Sam is planting trees on the upper half region (separated by the left diagonal)
of the square shared field.

For every value of ‘N’, print the field if the trees are represented by ‘*’.

Example:
Input: ‘N’ = 3

Output:
* * *
* *
*
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= T <= 10
1  <= N <= 25
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
* * *
* *
*
Sample Input 2 :
1
Sample Output 2 :
*
Sample Input 3 :
4
Sample Output 3 :
* * * *
* * *
* *
*

*/

#include <bits/stdc++.h>
using namespace std;

void seeding(int n) {
    // Write your code here.
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    seeding(n);
    return 0;
}