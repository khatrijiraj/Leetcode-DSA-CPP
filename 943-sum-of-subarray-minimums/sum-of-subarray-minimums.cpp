class Solution {
private:
    vector<int> PrevSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> PSE(n, 0);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }
            PSE[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        return PSE;
    }

    vector<int> NextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> NSE(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                stk.pop();
            }
            NSE[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        return NSE;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> PSE = PrevSmallerEle(arr);
        vector<int> NSE = NextSmallerEle(arr);

        int result = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < arr.size(); i++) {
            int pre = i - PSE[i];
            int nxt = NSE[i] - i;

            long long curr = (1l * pre * nxt * arr[i]) % mod;
            result = (result + curr) % mod;
        }

        return (int)result;
    }
};