class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int size = nums.size();

        unordered_map<int, int> mpp;

        int total = 0;

        //counting products of pairs
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                mpp[nums[i] * nums[j]]++;
            }
        }

        for (auto [prod, count] : mpp) {
            // (n * (n - 1)) / 2.
            int pairs = (count - 1) * count / 2;
            // 8 possible comibnation of arrangement of a*b = c*c
            /*
                ab = cd
                ba = cd
                ab = dc
                ba = dc
                cd = ab
                cd = ba
                dc = ab
                dc = ba
             */
            total += 8 * pairs;
        }

        return total;
    }
};