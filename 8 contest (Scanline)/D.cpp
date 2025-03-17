#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Event {
    int time;
    int type;
 
    Event(int t, int tp) : time(t), type(tp) {}
 
    bool operator<(const Event &other) const {
        if (time != other.time) return time < other.time;
        return type < other.type;
    }
};
 
int to_seconds(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<Event> events;
    
    for (int i = 0; i < n; i++) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
 
        int start = to_seconds(h1, m1, s1);
        int end = to_seconds(h2, m2, s2);
 
        if (start == end) {
            events.emplace_back(0, 1);
            events.emplace_back(86400, -1);
        } else if (start < end) {
            events.emplace_back(start, 1);
            events.emplace_back(end, -1);
        } else {
            events.emplace_back(start, 1);
            events.emplace_back(86400, -1);
            events.emplace_back(0, 1);
            events.emplace_back(end, -1);
        }
    }
 
    sort(events.begin(), events.end());
 
    int active_counters = 0, last_time = 0, full_work_time = 0;
 
    for (const auto &event : events) {
        if (active_counters == n) {
            full_work_time += event.time - last_time;
        }
        active_counters += event.type;
        last_time = event.time;
    }
 
    cout << full_work_time << "\n";
    return 0;
}