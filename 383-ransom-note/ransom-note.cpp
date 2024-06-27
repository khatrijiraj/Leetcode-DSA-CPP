class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mpp;
        for(char ch : magazine){
            mpp[ch]++;
        }

        for(char ch : ransomNote){
            if(mpp[ch] > 0){
                mpp[ch]--;
            } else if(mpp[ch] == 0){
                return false;
            }
        }
        return true;
    }
};