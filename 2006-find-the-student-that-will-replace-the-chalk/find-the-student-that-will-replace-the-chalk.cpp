class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        /* int size = chalk.size();
        int idx = 0;
        while(true){
            if(k < chalk[idx]){
                return idx;
            }
            k -= chalk[idx];
            idx = (idx + 1) % size;
        }
        return -1; */

        int size = chalk.size();
        long total = 0;
        for (auto it : chalk) {
            total += it;
        }

        k = k % total;

        for (int i = 0; i < size; i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};