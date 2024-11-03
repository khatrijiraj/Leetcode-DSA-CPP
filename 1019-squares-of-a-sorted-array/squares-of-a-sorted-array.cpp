class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;

        for (auto it : nums) {
            result.push_back(abs(it) * abs(it));
        }

        sort(result.begin(), result.end());

        return result;
    }
};