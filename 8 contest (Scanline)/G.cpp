#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
struct Event {
    int time;
    int begin_time;
    int type;
};
 
bool compareEvents(const Event &a, const Event &b) {
    if (a.time != b.time)
        return a.time < b.time;
    return a.type < b.type;
}
 
int main() {
    int N;
    cin >> N;
    vector<Event> events;
    set<int> ad_time;
 
    for (int i = 0; i < N; i++) {
        int S, T;
        cin >> S >> T;
        events.push_back({S, -1, 1});
        events.push_back({T, S, -1});
    }
 
    sort(events.begin(), events.end(), compareEvents);
 
    for (const auto &e : events) {
        if (e.type == 1) {
            continue;
        }
        
        int count = distance(ad_time.lower_bound(e.begin_time), ad_time.upper_bound(e.time));
 
        if (count == 0) {
            ad_time.insert(e.time - 1);
            ad_time.insert(e.time);
        } else if (count == 1) {
            if (ad_time.count(e.time)) {
                ad_time.insert(e.time - 1);
            } else {
                ad_time.insert(e.time);
            }
        }
    }
 
    cout << ad_time.size() << '\n';
    for (int time : ad_time) {
        cout << time << " ";
    }
    cout << '\n';
 
    return 0;
}