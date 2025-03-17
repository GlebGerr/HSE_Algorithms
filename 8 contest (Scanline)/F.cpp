#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
using namespace std;
 
struct Moment {
    int timestamp;
    int action;
    int id;
};
 
bool eventComparator(const Moment &a, const Moment &b) {
    if (a.timestamp != b.timestamp)
        return a.timestamp < b.timestamp;
    return a.action > b.action;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int count;
    cin >> count;
 
    vector<Moment> timeline;
    vector<int> encounters(count, 0);
    vector<int> entryOrder(count, 0);
    unordered_set<int> present;
    int totalEntries = 0;
 
    for (int i = 0; i < count; i++) {
        int start, end;
        cin >> start >> end;
        timeline.push_back({start, 1, i});
        timeline.push_back({end, -1, i});
    }
 
    sort(timeline.begin(), timeline.end(), eventComparator);
 
    for (const auto &moment : timeline) {
        if (moment.action == 1) {
            encounters[moment.id] = present.size();
            totalEntries++;
            entryOrder[moment.id] = totalEntries;
            present.insert(moment.id);
        } else {
            present.erase(moment.id);
            encounters[moment.id] += totalEntries - entryOrder[moment.id];
        }
    }
 
    for (int i = 0; i < count; i++) {
        cout << encounters[i] << '\n';
    }
    return 0;
}