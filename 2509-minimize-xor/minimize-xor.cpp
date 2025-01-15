class Solution {
private:
    bool isbitset(int num, int pos) { return (num & (1 << pos)); }

    void setbit(int& num, int pos) { num |= (1 << pos); }

public:
    int minimizeXor(int num1, int num2) {
        int requiredbits = __builtin_popcount(num2);

        int x = 0;

        for (int bit = 30; bit >= 0 && requiredbits > 0; bit--) {
            if (isbitset(num1, bit)) {
                setbit(x, bit);
                requiredbits--;
            }
        }

        for (int bit = 0; bit < 31 && requiredbits > 0; bit++) {
            if (!isbitset(x, bit)) {
                setbit(x, bit);
                requiredbits--;
            }
        }

        return x;
    }
};