class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int size = customers.size();
        
        int satisfied = 0;
        for (int i = 0; i < size; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }
       
        int canbesatisfied = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                canbesatisfied += customers[i];
            }
        }
        
        int maxi = canbesatisfied;
        for (int i = minutes; i < size; i++) {
            if (grumpy[i - minutes] == 1) {
                canbesatisfied -= customers[i - minutes];
            }
            if (grumpy[i] == 1) {
                canbesatisfied += customers[i];
            }
            maxi = max(maxi, canbesatisfied);
        }
        
        return satisfied + maxi;
    }
};
