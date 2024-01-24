/* Problem statement
You are given an integer ‘n’.



Print “Raj Khatri ” ‘n’ times, without using a loop.



Example:
Input: ‘n’  = 4

Output:
Raj Khatri Raj Khatri Raj Khatri Raj Khatri

Explanation: “Raj Khatri” is printed 4 times.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3


Sample Output 1:
Raj Khatri Raj Khatri Raj Khatri


Explanation of sample output 1:
“Raj Khatri” is printed 3 times.

Sample Input 2:
5


Sample Output 2:
Raj Khatri Raj Khatri Raj Khatri Raj Khatri Raj Khatri


Expected Time Complexity:
Try to solve this in O(n).


Expected Space Complexity:
Try to solve this in O(n).


Constraints:
1 <= 'n' <= 10^4

Time Limit: 1 sec */

#include <bits/stdc++.h>
using namespace std;

vector<string> PrintNTimes(int n) {
    if (n <= 0) {
        return {};
    }
    vector<string> temp = PrintNTimes(n - 1);
    temp.push_back("Raj Khatri");
    return temp;
}

int main() {
    int n;
    cin >> n;

    vector<string> temp = PrintNTimes(n);
    for (auto i : temp) {
        cout << i << " ";
    }
    return 0;
}