class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            } else if(!isVowel(s[left]) && isVowel(s[right])){
                left++;
            } else if(isVowel(s[left]) && !isVowel(s[right])){
                right--;
            } else {
                left++;
                right--;
            }
        }
        return s;
    }

private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
};