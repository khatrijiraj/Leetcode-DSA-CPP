class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> stt;
        for (auto& it : allowed) {
            stt.insert(it);
        }

        int count = 0;
        for (auto& it : words) {
            bool isconsistent = true;
            for (auto& it1 : it) {
                if (stt.find(it1) == stt.end()) {
                    isconsistent = false;
                    break;
                }
            }
            if (isconsistent) {
                count++;
            }
        }

        return count;
    }
};