class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long total_waiting_time = 0;
        int current_time = 0;

        for (auto it : customers) {
            int arrival_time = it[0];
            int time_required = it[1];

            if (current_time < arrival_time) {
                current_time = arrival_time;
            }

            current_time += time_required;
            total_waiting_time += current_time - arrival_time;
        }

        return static_cast<double>(total_waiting_time) / customers.size();
    }
};