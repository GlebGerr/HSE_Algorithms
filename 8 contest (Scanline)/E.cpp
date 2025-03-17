#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
 
struct Rectangle {
    int x1, y1, x2, y2;
};
 
struct Event {
    int x;
    int type;
    int y1, y2;
 
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};
 
int main() {
    int N;
    cin >> N;
 
    vector<Rectangle> rectangles(N);
    for (int i = 0; i < N; ++i) {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
    }
 
    vector<Event> events;
    for (const auto& rect : rectangles) {
        events.push_back({rect.x1, 1, rect.y1, rect.y2});
        events.push_back({rect.x2, -1, rect.y1, rect.y2});
    }
 
    sort(events.begin(), events.end());
 
    multiset<pair<int, int>> activeRectangles;
    long long totalArea = 0;
    int prevX = 0;
 
    for (const auto& event : events) {
        int currentX = event.x;
        int type = event.type;
        int y1 = event.y1;
        int y2 = event.y2;
 
        if (!activeRectangles.empty()) {
            int totalYLength = 0;
            int startY = -1, endY = -1;
 
            for (const auto& rect : activeRectangles) {
                if (rect.first > endY) {
                    if (startY != -1) {
                        totalYLength += endY - startY;
                    }
                    startY = rect.first;
                    endY = rect.second;
                } else {
                    endY = max(endY, rect.second);
                }
            }
 
            if (startY != -1) {
                totalYLength += endY - startY;
            }
 
            totalArea += (long long)totalYLength * (currentX - prevX);
        }
 
        if (type == 1) {
            activeRectangles.insert({y1, y2});
        } else {
            activeRectangles.erase(activeRectangles.find({y1, y2}));
        }
 
        prevX = currentX;
    }
 
    cout << totalArea << endl;
 
    return 0;
}