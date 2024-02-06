/* Problem statement
You have been given an array ‘a’ of ‘n’ unique non-negative integers.



Find the second largest and second smallest element from the array.



Return the two elements (second largest and second smallest) as another array of
size 2.



Example :
Input: ‘n’ = 5, ‘a’ = [1, 2, 3, 4, 5]
Output: [4, 2]

The second largest element after 5 is 4, and the second smallest element after 1
is 2. Detailed explanation ( Input/output format, Notes, Images ) Sample Input 1
:
4
3 4 5 2
Sample Output 1 :
4 3
Explanation For Sample Input 1 :
The second largest element after 5 is 4 only, and the second smallest element
after 2 is 3. Sample Input 2 :
5
4 5 3 6 7
Sample Output 2 :
6 4
Expected Time Complexity:
O(n), Where ‘n’ is the size of an input array ‘a’.
Constraints:
2 ≤ 'n' ≤ 10^5
0 ≤ 'a'[i] ≤ 10^9

Time limit: 1 sec */

#include <bits/stdc++.h>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> arr) {
    // Write your code here.
    int max = INT_MIN, min = INT_MAX, secondmax = 0, secondmin = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            secondmax = max;
            max = arr[i];
        } else if (arr[i] > secondmax && arr[i] != max) {
            secondmax = arr[i];
        }

        if (arr[i] < min) {
            secondmin = min;
            min = arr[i];
        } else if (arr[i] < secondmin && arr[i] != min) {
            secondmin = arr[i];
        }
    }
    return {secondmax, secondmin};
}

int main() {
    int n;
    cin >> n;
    int ele;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        arr.push_back(ele);
    }
    vector<int> arr2 = getSecondOrderElements(n, arr);
    for (auto i : arr2) {
        cout << i << " ";
    }
    return 0;
}