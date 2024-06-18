class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {

        vector<pair<int, int>> jobs(difficulty.size());

        for (int i = 0; i < difficulty.size(); i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        sort(worker.begin(), worker.end());

        int result = 0;
        int bestprofit = 0;

        int index = 0;

        for (auto it : worker) {
            while (index < difficulty.size() && jobs[index].first <= it) {
                bestprofit = max(bestprofit, jobs[index].second);
                ++index;
            }
            result += bestprofit;
        }

        return result;
    }
};