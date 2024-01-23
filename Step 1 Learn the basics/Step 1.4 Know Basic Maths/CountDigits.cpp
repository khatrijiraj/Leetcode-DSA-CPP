#include <bits/stdc++.h>
using namespace std;

int countdigits(int num) {
    int count = 0;
    int original = num;
    while (num > 0) {
        int lastdigit = num % 10;
        if (lastdigit > 0 && original % lastdigit == 0) {
            count++;
        }
        num = num / 10;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countdigits(n);
    return 0;
}