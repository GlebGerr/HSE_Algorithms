#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int M;
    cin >> M;
    
    vector<pair<int, int>> segments;
    while (true) {
        int L, R;
        cin >> L >> R;
        if (L == 0 && R == 0) break;
        segments.push_back({L, R});
    }
    
    sort(segments.begin(), segments.end());
    
    vector<pair<int, int>> result;
    int current = 0;
    size_t i = 0;
    while (current < M) {
        int bestR = current;
        size_t bestIdx = i;
        
        while (i < segments.size() && segments[i].first <= current) {
            if (segments[i].second > bestR) {
                bestR = segments[i].second;
                bestIdx = i;
            }
            i++;
        }
        
        if (bestR <= current) {
            cout << "No solution" << endl;
            return 0;
        }
        
        result.push_back(segments[bestIdx]);
        current = bestR;
    }
    
    cout << result.size() << endl;
    for (const auto& seg : result) {
        cout << seg.first << " " << seg.second << endl;
    }
    
    return 0;
}