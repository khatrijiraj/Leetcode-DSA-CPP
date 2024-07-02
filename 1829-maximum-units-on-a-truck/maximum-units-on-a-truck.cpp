class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });

        int totalunits = 0;

        for (auto boxtype : boxTypes) {
            int numberofbox = boxtype[0];
            int unitsperbox = boxtype[1];

            int boxestotake = min(truckSize, numberofbox);

            totalunits += boxestotake * unitsperbox;
            truckSize -= boxestotake;

            if (truckSize == 0) {
                break;
            }
        }

        return totalunits;
    }
};