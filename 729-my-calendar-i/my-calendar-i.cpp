class MyCalendar {
private:
    vector<pair<int, int>> events;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        for (auto& it : events) {
            if (max(it.first, start) < min(it.second, end)) {
                return false;
            }
        }
        events.push_back({start, end});
        return true;
    }
};
