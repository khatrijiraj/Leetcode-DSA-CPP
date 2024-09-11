class Solution {
private:
    void helper(int index, int target, vector<int>& candidates,
                vector<int>& current, vector<vector<int>>& result) {
        if (index == candidates.size()) {
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }

        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            helper(index, target - candidates[index], candidates, current,
                   result);
            current.pop_back();
        }
        helper(index + 1, target, candidates, current, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        helper(0, target, candidates, current, result);

            return result;
    }
};