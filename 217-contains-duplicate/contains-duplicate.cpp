class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int it : nums) {
            if (seen.find(it) != seen.end()) {
                return true;
            }
            seen.insert(it);
        }
        return false;
    }
};