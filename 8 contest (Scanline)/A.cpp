#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> segments(N);
    for (int i = 0; i < N; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    sort(segments.begin(), segments.end());
    
    vector<pair<int, int>> merged;
    for (const auto& seg : segments) {
        if (merged.empty() || merged.back().second < seg.first) {
            merged.push_back(seg);
        } else {
            merged.back().second = max(merged.back().second, seg.second);
        }
    }
    
    cout << merged.size() << endl;
    for (const auto& seg : merged) {
        cout << seg.first << " " << seg.second << endl;
    }
    
    return 0;
}