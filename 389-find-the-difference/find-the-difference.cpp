class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    char findTheDifference(string s, string t) {
        char result = 0;

        for (char ch : s){
            result ^= ch;
        }

        for(char ch : t){
            result ^= ch;
        }

        return result;
    }
};