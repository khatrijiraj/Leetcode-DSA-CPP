/* Problem statement
Given an integer ‘n’, return first n Fibonacci numbers using a generator
function.



Example:
Input: ‘n’ = 5

Output: 0 1 1 2 3

Explanation: First 5 Fibonacci numbers are: 0, 1, 1, 2, and 3.
Note:
You don't need to print anything. Just implement the given function.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5
Sample Output 1:
0 1 1 2 3
Explanation Of Sample Input 1:
The first 5 Fibonacci numbers are 0, 1, 1, 2, and 3.
Sample Input 2:
3
Sample Output 2:
0 1 1
Explanation Of Sample Input 2:
The first 5 Fibonacci numbers are 0, 1, 1.
Expected time complexity
The expected time complexity is O(n).
Constraints:
1 <= n <= 45
Time Limit: 1 s */

#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacciSeries(int n) {
    if (n == 0) {
        return {};
    }
    if (n == 1) {
        return {0};
    }
    if (n == 2) {
        return {0, 1};
    }
    vector<int> temp = fibonacciSeries(n - 1);
    temp.push_back(temp[temp.size() - 1] + temp[temp.size() - 2]);
    return temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> temp = fibonacciSeries(n);
    for (auto i : temp) {
        cout << i << " ";
    }
    return 0;
}