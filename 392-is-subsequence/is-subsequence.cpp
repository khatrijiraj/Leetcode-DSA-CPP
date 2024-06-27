class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();

        if(slen == 0){
            return true;
        }

        int left = 0;
        int right = 0;

        while(right < tlen){
            if(s[left] == t[right]){
                left++;
                if(left == slen){
                    return true;
                }
            }
            right++;
        }

        return false;
    }
};