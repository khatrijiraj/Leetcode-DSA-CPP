class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxheap;

        for (auto& it : classes) {
            double currentpr = (double)it[0] / it[1];
            double newpr = (double)(it[0] + 1) / (it[1] + 1);

            double diffpr = newpr - currentpr;

            maxheap.push({diffpr, {it[0], it[1]}});
        }

        while (extraStudents--) {
            auto [pr, cls] = maxheap.top();
            maxheap.pop();

            auto [pass, total] = cls;

            pass += 1, total += 1;

            double currentpr = (double)pass / total;
            double newpr = (double)(pass + 1) / (total + 1);

            double diffpr = newpr - currentpr;
            maxheap.push({diffpr, {pass, total}});
        }

        double result = 0;
        while (!maxheap.empty()) {
            auto [pr, cls] = maxheap.top();
            maxheap.pop();

            auto [pass, total] = cls;
            result += (double)pass / total;
        }

        return result / classes.size();
    }
};