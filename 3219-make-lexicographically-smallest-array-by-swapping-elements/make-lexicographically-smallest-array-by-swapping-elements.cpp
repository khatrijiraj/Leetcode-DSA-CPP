class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortednums(nums);
        sort(sortednums.begin(), sortednums.end());

        int groupnumber = 0;
        unordered_map<int, int> mppgroup;

        mppgroup[sortednums[0]] = groupnumber;
        unordered_map<int, vector<int>> grouplist;

        grouplist[groupnumber] = {sortednums[0]};

        for (int i = 1; i < nums.size(); i++) {
            if (abs(sortednums[i] - sortednums[i - 1]) > limit) {
                groupnumber++;
            }

            mppgroup[sortednums[i]] = groupnumber;

            grouplist[groupnumber].push_back(sortednums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = mppgroup[num];

            nums[i] = grouplist[group].front();
            grouplist[group].erase(grouplist[group].begin());
        }

        return nums;
    }
};
