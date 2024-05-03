int mod = 1e9 + 7;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
auto __sync_ios_stdio = ios_base::sync_with_stdio(false);
auto __untie_cin = cin.tie(nullptr);

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftOptions;
        vector<int> rightOptions;
        stack<pair<int, int>> stk;

        for (int i = 0; i < arr.size(); i++) {
            while (!stk.empty() && stk.top().first >= arr[i]) {
                stk.pop();
            }
            leftOptions.push_back((stk.empty() ? i + 1 : i - stk.top().second));
            stk.push({arr[i], i});
        }

        while (!stk.empty())
            stk.pop();

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top().first > arr[i]) {
                stk.pop();
            }
            rightOptions.push_back(
                (stk.empty() ? n - i : stk.top().second - i));
            stk.push({arr[i], i});
        }
        reverse(rightOptions.begin(), rightOptions.end());

        long long res = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long curr =
                (1ll * leftOptions[i] * rightOptions[i] * arr[i]) % mod;
            res = (res + curr) % mod;
        }
        return (int)res;
    }
};