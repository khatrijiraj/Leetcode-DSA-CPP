class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        ios_base::sync_with_stdio(false);
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.emplace_back(capital[i], profits[i]);
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap;

        int currentCapital = w;
        int projectIndex = 0;

        for (int i = 0; i < k; i++) {
            while (projectIndex < projects.size() &&
                   projects[projectIndex].first <= currentCapital) {
                maxProfitHeap.push(projects[projectIndex].second);
                ++projectIndex;
            }

            if (maxProfitHeap.empty()) {
                break;
            }

            currentCapital += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return currentCapital;
    }
};