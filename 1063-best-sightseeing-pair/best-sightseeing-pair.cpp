class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> lastmaxi(n, 0);
        //(value[i] + i) + (value[j] - j)
        lastmaxi[0] = values[0] + 0;

        for (int i = 1; i < n; i++) {
            lastmaxi[i] = max((values[i] + i), lastmaxi[i - 1]);
        }

        for (auto it : lastmaxi) {
            cout << it << endl;
        }

        int result = 0;

        for (int j = 1; j < n; j++) {
            result = max(result, (lastmaxi[j - 1] + values[j] - j));
        }

        return result;
    }
};