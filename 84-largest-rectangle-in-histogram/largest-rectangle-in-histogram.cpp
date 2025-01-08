class Solution {
private:
    vector<int> nextSmaller(vector<int>& arr, int n) {
        stack<int> stk;

        vector<int> temp(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];

            while (!stk.empty() && arr[stk.top()] >= curr) {
                stk.pop();
            }

            if (stk.empty()) {
                temp[i] = -1;
            } else {
                temp[i] = stk.top();
            }
            stk.push(i);
        }

        return temp;
    }

    vector<int> prevSmaller(vector<int>& arr, int n) {
        stack<int> stk;

        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];

            while (!stk.empty() && arr[stk.top()] >= curr) {
                stk.pop();
            }

            if (stk.empty()) {
                temp[i] = -1;
            } else {
                temp[i] = stk.top();
            }
            stk.push(i);
        }

        return temp;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> NSE(n);
        NSE = nextSmaller(heights, n);

        vector<int> PSE(n);
        PSE = prevSmaller(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++) {
            int length = heights[i];

            if (NSE[i] == -1) {
                NSE[i] = n;
            }

            int breadth = NSE[i] - PSE[i] - 1;

            area = max(area, length * breadth);
        }

        return area;
    }
};