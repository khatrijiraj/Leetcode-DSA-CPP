class Solution {
    long genPalin(long half, bool iseven) {
        string halfstr = to_string(half);
        string palindrom = halfstr;

        if (!iseven) {
            halfstr.pop_back();
        }

        reverse(halfstr.begin(), halfstr.end());
        palindrom += halfstr;
        return stol(palindrom);
    }

public:
    string nearestPalindromic(string n) {
        int length = n.size();
        long num = stol(n);
        long halfpart = stol(n.substr(0, (length + 1) / 2));
        vector<long> temp;
        temp.push_back(genPalin(halfpart, length % 2 == 0));
        temp.push_back(genPalin(halfpart + 1, length % 2 == 0));
        temp.push_back(genPalin(halfpart - 1, length % 2 == 0));
        temp.push_back(pow(10, length - 1) - 1);
        temp.push_back(pow(10, length) + 1);

        long result = -1;
        long mini = LONG_MAX;

        for (auto& it : temp) {
            if (it == num) {
                continue;
            }

            long diff = abs(it - num);

            if (diff < mini || (diff == mini && it < result)) {
                mini = diff;
                result = it;
            }
        }

        return to_string(result);
    }
};