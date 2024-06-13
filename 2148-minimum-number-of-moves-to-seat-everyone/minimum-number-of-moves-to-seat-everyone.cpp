class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int count = 0;
        for (int i = 0; i < seats.size(); i++) {
            count += abs(seats[i] - students[i]);
        }
        return count;
    }
};