class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        /*
            let original array = [a,b,c,d,e]
            if derived array = [1,0,1,0,0] (assuming)

            then derived is xor of adjacent element
            therefor derived = [(a^b), (b^c), (c^d), (d^e), (e^a)];

            one important observation here is if we xor all derived elements
            then the result xor will be 0 since all elements are coming twice
            if the derived array is valid.

            we can also count number of 1's in derived array
            if they are even then they will cancel each other else no

            TC:- O(N)

            cool observation based question
         */

        int xori = 0;
        for (auto it : derived) {
            xori ^= it;
        }
        return xori == 0;
    }
};