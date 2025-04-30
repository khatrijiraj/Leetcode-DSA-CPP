class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto it : nums) {
            int num = it;
            int digits = 0;
            while (num) {
                digits++;
                num /= 10;
            }
            if (digits % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};