class Solution {
public:
    string compressedString(string word) {
        string result = "";

        int i = 0;

        while (i < word.length()) {
            int count = 0;
            char ch = word[i];

            while (i < word.length() && count < 9 && word[i] == ch) {
                count++;
                i++;
            }

            result += to_string(count) + ch;
        }

        return result;
    }
};