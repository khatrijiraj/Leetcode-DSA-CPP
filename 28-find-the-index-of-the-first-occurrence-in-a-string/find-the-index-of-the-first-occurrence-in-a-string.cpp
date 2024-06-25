class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        size_t index = haystack.find(needle);

        if (index == string::npos) {
            return -1;
        }

        return static_cast<int>(index);
    }
};