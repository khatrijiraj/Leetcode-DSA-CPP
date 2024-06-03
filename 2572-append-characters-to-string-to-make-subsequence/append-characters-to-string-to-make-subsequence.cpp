class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);


        
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