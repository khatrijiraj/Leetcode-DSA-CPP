class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mpp;
        for(int it : arr1){
            mpp[it]++;
        }

        vector<int> result;
        for(int it: arr2){
            while(mpp[it]>0){
                result.push_back(it);
                mpp[it]--;
            }
        }

        vector<int> remaining;
        for(auto& it : mpp){
            while(it.second>0){
                remaining.push_back(it.first);
                it.second--;
            }
        }

        sort(remaining.begin(), remaining.end());

        result.insert(result.end(), remaining.begin(), remaining.end());

        return result;
    }
};