class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> stt;
        for (auto it : nums) {
            if (it < k) {
                return -1;
            } else if (it > k) {
                stt.insert(it);
            }
        }
        return stt.size();
    }
};