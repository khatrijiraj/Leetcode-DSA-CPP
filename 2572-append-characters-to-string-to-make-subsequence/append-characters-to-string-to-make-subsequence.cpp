class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        int sizeofs = s.length();
        int sizeoft = t.length();
        
        for (int i = 0; i < sizeofs; i++) {
            if (j < sizeoft && s[i] == t[j]) {
                j++;
            }
        }
        
        return sizeoft - j;
    }
};