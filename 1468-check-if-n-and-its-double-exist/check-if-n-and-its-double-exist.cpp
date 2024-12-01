class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> stt;

        for (auto it : arr) {
            if (stt.find(it * 2) != stt.end() ||
                (it % 2 == 0 && stt.find(it / 2) != stt.end())) {
                return true;
            }
            stt.insert(it);
        }

        return false;
    }
};
