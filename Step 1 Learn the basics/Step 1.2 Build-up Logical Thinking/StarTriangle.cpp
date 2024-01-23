/*
Problem statement
Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the
N-Star Triangle.

Example:
Input: ‘N’ = 3

Output:

  *
 ***
*****
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= N <= 20
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
  *
 ***
*****
Explanation Of Sample Input 1 :
The first row contains two spaces, followed by a star.
The second row contains one space, followed by three stars.
The third row contains five stars.
Sample Input 2 :
1
Sample Output 2 :
*
 */

#include <bits/stdc++.h>
using namespace std;

void nStarTriangle(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }

        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    nStarTriangle(n);
    return 0;
}