class Solution {
private:
    long long solve(string& str, string& suf, int limit) {
        long long count = 0;
        
        if (str.length() < suf.length()) {
            return 0;
        }
        
        string trail = str.substr(str.length() - suf.length());
        int remaining = str.length() - suf.length();

        for (int i = 0; i < remaining; i++) {
            int digit = str[i] - '0';
            if (digit <= limit) {
                count += digit * pow(limit + 1, remaining - i - 1);
            } else {
                count += pow(limit + 1, remaining - i);
                return count;
            }
        }

        if (trail >= suf) {
            count += 1;
        }

        return count;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string startstring = to_string(start - 1);
        string endstring = to_string(finish);

        return solve(endstring, s, limit) - solve(startstring, s, limit);
    }
};
