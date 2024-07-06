class Solution {
public:
    int passThePillow(int n, int time) {
        int currentPosition = 1;
        bool forward = true;

        for (int t = 0; t < time; ++t) {
            if (forward) {
                if (currentPosition == n) {
                    forward = false;
                    currentPosition--;
                } else {
                    currentPosition++;
                }
            } else {
                if (currentPosition == 1) {
                    forward = true;
                    currentPosition++;
                } else {
                    currentPosition--;
                }
            }
        }

        return currentPosition;
    }
};