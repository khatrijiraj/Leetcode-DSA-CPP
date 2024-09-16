class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int result = INT_MAX;
        vector<int> minutes;

        for (auto it : timePoints) {
            int hour = stoi(it.substr(0, 2));
            int min = stoi(it.substr(3, 2));
            int time = hour * 60 + min;
            minutes.push_back(time);
        }

        sort(minutes.begin(), minutes.end());

        for (int i = 1; i < minutes.size(); i++) {
            result = min(result, minutes[i] - minutes[i - 1]);
        }

        return min(result, ((24 * 60 - minutes.back()) + minutes[0]));
    }
};