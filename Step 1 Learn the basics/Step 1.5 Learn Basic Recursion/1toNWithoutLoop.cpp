/* Problem statement
You are given an integer ‘n’.



Your task is to return an array containing integers from 1 to ‘n’ (in increasing
order) without using loops.



Example:
Input: ‘n’ = 5

Output: 1 2 3 4 5

Explanation: An array containing integers from ‘1’ to ‘n’ is [1, 2, 3, 4, 5].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5
Sample Output 1 :
1 2 3 4 5
Explanation Of Sample Input 1:
The array contains all integers from 1 to 5 in ascending order.
Sample Input 2:
2
Sample Output 2:
1 2
Explanation Of Sample Input 2:
The array contains all integers from 1 to 2 in ascending order.
Expected Time Complexity:
The expected time complexity is O(n), where 'n' is the given integer.
Constraints:
1 <= n <= 10^6

Time Limit: 1-sec */

#include <bits/stdc++.h>
using namespace std;

vector<int> PrintN(int n) {
    if (n <= 0) {
        return {};
    }
    vector<int> temp = PrintN(n - 1);
    temp.push_back(n);
    return temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> temp = PrintN(n);
    for (auto it : temp) {
        cout << it << " ";
    }
    return 0;
}