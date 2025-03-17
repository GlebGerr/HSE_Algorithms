#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<int> L(n), R(n), P(m), answer(m);
    vector<pair<int, int>> points;
 
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        if (L[i] > R[i]) swap(L[i], R[i]);
    }
 
    for (int i = 0; i < m; i++) {
        cin >> P[i];
        points.emplace_back(P[i], i);
    }
 
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    sort(points.begin(), points.end());
 
    int l_ptr = 0, r_ptr = 0, active_segments = 0;
 
    for (auto [x, idx] : points) {
        while (l_ptr < n && L[l_ptr] <= x) {
            active_segments++;
            l_ptr++;
        }
        while (r_ptr < n && R[r_ptr] < x) {
            active_segments--;
            r_ptr++;
        }
        answer[idx] = active_segments;
    }
 
    for (int i = 0; i < m; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
 
    return 0;
}