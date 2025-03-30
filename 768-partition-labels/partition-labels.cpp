class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mpp(26, 0);
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> size;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, mpp[s[i] - 'a']);
            if (i == end) {
                size.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return size;
    }
};