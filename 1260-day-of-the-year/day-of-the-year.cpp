class Solution {
private:
    bool isleap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

public:
    int dayOfYear(string date) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int day = stoi(date.substr(8, 2));
        int month = stoi(date.substr(5, 2));
        int year = stoi(date.substr(0, 4));

        if (isleap(year)) {
            daysInMonth[1] = 29;
        }

        int dayOfYear = day;
        
        for (int i = 0; i < month - 1; i++) {
            dayOfYear += daysInMonth[i];
        }

        return dayOfYear;
    }
};
