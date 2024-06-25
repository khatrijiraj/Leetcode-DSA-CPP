class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long ele = 1;
        ans.push_back(ele);

        for (int col = 1; col <= rowIndex; col++) {
            ele *= (rowIndex - col + 1);
            ele /= col;
            ans.push_back(ele);
        }

        return ans;
    }
};