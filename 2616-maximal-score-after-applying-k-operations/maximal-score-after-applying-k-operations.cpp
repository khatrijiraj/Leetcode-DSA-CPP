class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pqmaxi(nums.begin(), nums.end());
        long long answer = 0;

        while (k--) {
            int temp = pqmaxi.top();
            pqmaxi.pop();

            answer += temp;
            temp = ceil(temp / 3.0);

            pqmaxi.push(temp);
        }

        return answer;
    }
};