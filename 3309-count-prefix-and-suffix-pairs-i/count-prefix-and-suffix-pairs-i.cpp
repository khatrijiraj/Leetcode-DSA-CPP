class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        int size1 = str1.length();
        int size2 = str2.length();

        if (size1 > size2) {
            return false;
        }

        if (str2.find(str1) == 0 && str2.rfind(str1) == size2 - size1) {
            return true;
        }

        return false;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (i < j && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};