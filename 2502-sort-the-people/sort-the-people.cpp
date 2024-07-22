class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> mpp;

        for (int i = 0; i < heights.size(); i++) {
            mpp.push_back({heights[i], names[i]});
        }

        sort(mpp.begin(), mpp.end(),
             [](pair<int, string>& a, pair<int, string>& b) {
                 return a.first > b.first;
             });

        vector<string> result;

        for (auto it : mpp) {
            result.push_back(it.second);
        }

        return result;
    }
};