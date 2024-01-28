/* Problem statement
Given the 'start' and the 'end'' positions of the array 'input'. Your task is to
sort the elements between 'start' and 'end' using quick sort.



Note :
Make changes in the input array itself.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 2 3 5 7
Sample Output 2 :
1 2 3 5 7
Constraints :
1 <= N <= 10^3
0 <= input[i] <= 10^9 */

#include <bits/stdc++.h>
using namespace std;

int partitionArray(int input[], int start, int end) {
    // Write your code here
    int i = start;
    int j = end;
    int pivot = input[start];
    while (i < j) {
        while (input[i] <= pivot && i <= end - 1) {
            i++;
        }
        while (input[j] > pivot && j >= start + 1) {
            j--;
        }
        if (i < j) {
            swap(input[i], input[j]);
        }
    }
    swap(input[j], input[start]);
    return j;
}

void quickSort(int input[], int start, int end) {
    if (start < end) {
        int index = partitionArray(input, start, end);
        quickSort(input, start, index - 1);
        quickSort(input, index + 1, end);
    }
}

int main() {
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout<<"Before: ";
    for (auto i : input) {
        cout << i << " ";
    }

    quickSort(input, 0, n);
    
    cout<<"\nAfter: ";
    for (auto i : input) {
        cout << i << " ";
    }
    return 0;
}