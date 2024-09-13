class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto& it : queries) {
            int left = it[0];
            int right = it[1];
            int xori = 0;
            for (int i = left; i <= right; i++) {
                xori = xori ^ arr[i];
            }
            result.push_back(xori);
        }
        return result;
    }
};