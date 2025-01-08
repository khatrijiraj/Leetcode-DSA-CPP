class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (auto it : asteroids) {
            if (it > 0) {
                stk.push(it);
            } else {
                while (!stk.empty() && stk.top() > 0 && stk.top() < abs(it)) {
                    stk.pop();
                }
                if (stk.empty() || stk.top() < 0) {
                    stk.push(it);
                }
                if(!stk.empty() && stk.top() == abs(it)){
                    stk.pop();
                }
            }
        }

        vector<int> result;

        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};