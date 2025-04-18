class Solution {
private:
    string solve(int n) {
        if (n == 1) {
            return "1";
        }

        string temp = solve(n - 1);
        string res = "";

        int i = 0;
        while (i < temp.size()) {
            int j = i + 1;
            while (j < temp.size() && temp[j] == temp[i]) {
                j++;
            }
            int count = j - i;
            res += to_string(count);
            res += temp[i];
            i = j;
        }

        return res;
    }

public:
    string countAndSay(int n) { return solve(n); }
};