class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int count = 0;
        while(temp){
            int rightmostsetbit = temp & -temp;
            temp -= rightmostsetbit;
            count++;
        }
        return count;
    }
};