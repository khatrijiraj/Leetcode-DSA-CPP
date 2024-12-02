class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);

        string temp = "";
        int word = 1;
        
        while (ss >> temp) {
            if (temp.substr(0, searchWord.length()) == searchWord) {
                return word;
            }
            word++;
        }

        return -1;
    }
};