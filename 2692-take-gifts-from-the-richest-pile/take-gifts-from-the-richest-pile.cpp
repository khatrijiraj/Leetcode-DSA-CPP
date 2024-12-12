class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (auto it : gifts) {
            pq.push(it);
        }

        while (k--) {
            int ele = pq.top();
            pq.pop();
            int reduced = sqrt(ele);
            pq.push(reduced);
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};