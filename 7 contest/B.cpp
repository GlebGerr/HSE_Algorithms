#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> friends(n);

    for (int i = 0; i < n; ++i) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end());

    long long max_friendship = 0;
    long long current_friendship = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_friendship += friends[right].second;

        while (friends[right].first - friends[left].first >= d) {
            current_friendship -= friends[left].second;
            left++;
        }

        max_friendship = max(max_friendship, current_friendship);
    }

    cout << max_friendship << endl;

    return 0;
}