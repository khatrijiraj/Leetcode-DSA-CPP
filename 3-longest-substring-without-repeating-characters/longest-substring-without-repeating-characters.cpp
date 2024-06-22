class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        
        int maxLength = 0;
        int left = 0;

        for(int right = 0; right < s.length(); right++){
            char ch = s[right];
            if(mpp.find(ch) != mpp.end() && mpp[ch] >= left){
                left = ++mpp[ch];
            }

            mpp[ch] = right;

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};