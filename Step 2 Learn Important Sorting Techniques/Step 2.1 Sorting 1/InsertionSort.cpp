/* Problem statement
You are given an integer array 'arr' of size 'N'.



You must sort this array using 'Insertion Sort' recursively.



 Note:
Change in the input array itself. You don't need to return or print the
elements. Example: Input: ‘N’ = 7 'arr' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying insertion sort on the input array, the output is [1
2 3 4 6 13 28]. Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5
9 3 6 2 0
Sample Output 1:
0 2 3 6 9
Sample Input 2:
4
4 3 2 1
Sample Output 2:
1 2 3 4
Constraints :
0 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec */

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    // write your code here
    for (int i = 0; i < n; i++) {
        int prev = i;
        while (prev > 0 && arr[prev - 1] > arr[prev]) {
            int temp = arr[prev];
            arr[prev] = arr[prev - 1];
            arr[prev - 1] = temp;
            prev--;
        }
    }
}

int main() {
    int n = 5;
    int arr[] = {9, 3, 6, 2, 0};
    insertionSort(arr, n);
    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}