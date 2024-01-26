/* Problem statement
Given an array 'v' of 'n' numbers.



Your task is to find and return the highest and lowest frequency elements.


If there are multiple elements that have the highest frequency or lowest
frequency, pick the smallest element.



Example:
Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

Output: 1 2

Explanation: The element having the highest frequency is '1', and the frequency
is 3. The elements with the lowest frequencies are '2', '3', and '4'. Since we
need to pick the smallest element, we pick '2'. Hence we return [1, 2]. Detailed
explanation ( Input/output format, Notes, Images ) Sample Input 1 :
6
1 2 3 1 1 4
Sample Output 1 :
1 2
Sample Explanation 1:
Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

Output: 1 2

Explanation: The element having the highest frequency is '1', and the frequency
is 3. The elements with the lowest frequencies are '2', '3', and '4'. Since we
need to pick the smallest element, we pick '2'. Hence we return [1, 2]. Sample
Input 2 :
6
10 10 10 3 3 3
Sample Output 2 :
3 3
Sample Explanation 2:
Input: ‘n' = 6, 'v' = [10, 10, 10, 3, 3, 3]

Output: 3 3

Explanation: Since the frequency of '3' and '10' is 3. Therefore, the element
with the maximum and minimum frequency is '3'. Expected Time Complexity : The
expected time complexity is O(n), where n is the size of the array. Expected
Space Complexity : The expected time complexity is O(n), where n is the size of
the array. Constraints : 2 <=  n <= 10^4 1 <= v[i] <= 10^9 There are at least
two distinct elements in the array. Time Limit: 1 sec  */

#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int, int> freqMap;
    for (int it : v) {
        freqMap[it]++;
    }

    int max_frequency = 0;
    int max_element = INT_MAX;
    for (auto& i : freqMap) {
        if (i.second > max_frequency ||
            (i.second == max_frequency && i.first < max_element)) {
            max_frequency = i.second;
            max_element = i.first;
        }
    }

    int min_frequency = INT_MAX;
    int min_element = INT_MAX;
    for (auto i : freqMap) {
        if (i.second < min_frequency ||
            (i.second == min_frequency && i.first < min_element)) {
            min_frequency = i.second;
            min_element = i.first;
        }
    }
    return {max_element, min_element};
}

int main() {
    int n;
    cin >> n;
    vector<int> v = {1, 2, 3, 4, 5, 1, 1, 2};
    vector<int> temp = getFrequencies(v);
    for (auto i : temp) {
        cout << i << " ";
    }
    return 0;
}