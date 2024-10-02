class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return {};
        }

        vector<int> temp(arr.begin(), arr.end());

        sort(temp.begin(), temp.end());

        unordered_map<int, int> mpp;

        int rank = 1;
        int prev = temp[0];

        mpp[prev] = rank;

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] == temp[i - 1]) {
                mpp[temp[i]] = rank;
            } else {
                rank++;
                mpp[temp[i]] = rank;
            }
        }

        for (auto it : mpp) {
            cout << it.first << " " << it.second << ", ";
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mpp[arr[i]];
        }

        return arr;
    }
};