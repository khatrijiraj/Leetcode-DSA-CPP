class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mpp;
        for (auto it : answers) {
            mpp[it]++;
        }

        int total = 0;

        for (auto it : mpp) {
            int x = it.first;
            int count = it.second;

            int size = x + 1;
            int groups = ceil((double)count / size);

            total += groups * size;
        }

        return total;
    }
};