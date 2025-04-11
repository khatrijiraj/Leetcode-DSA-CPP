class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        while (low <= high) {
            if (low % 11 == 0 && low < 100) {
                count++;
            } else if (low >= 1000 && low < 10000) {
                int lefthalfsum = (low / 1000) + ((low / 100) % 10);
                int righthalsum = ((low / 10) % 10) + ((low / 1) % 10);
                if (lefthalfsum == righthalsum) {
                    count++;
                }
            }
            low++;
        }
        return count;
    }
};