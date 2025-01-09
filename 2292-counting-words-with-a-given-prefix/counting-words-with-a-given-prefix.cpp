class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int preflen = pref.length();
        for (auto it : words) {
            string worsub =
                it.substr(0, preflen); // substr(staringposition, size);
            if (worsub == pref) {
                count++;
            }
            /* or we can use this also
            if (it.find(pref) == 0) {
                count++;
            }
             */
        }
        return count;
    }
};