class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> mpp;

        for (int& it : hand) {
            mpp[it]++;
        }

        for (auto num = mpp.begin(); num != mpp.end(); ++num) {
            if (num->second > 0) {
                int start = num->first;
                int end = num->second;

                for (int j = 0; j < groupSize; ++j) {
                    if (mpp[start + j] < end) {
                        return false;
                    }
                    mpp[start + j] -= end;
                }
            }
        }

        return true;
    }
};