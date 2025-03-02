#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> droids(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> droids[i][j];
        }
    }

    vector<int> result(m, 0);
    int max_length = 0;
    int left = 0;

    vector<deque<int>> max_deques(m);

    vector<int> current_max(m, 0);

    for (int right = 0; right < n; ++right) {
        for (int j = 0; j < m; ++j) {
            while (!max_deques[j].empty() && droids[right][j] >= droids[max_deques[j].back()][j]) {
                max_deques[j].pop_back();
            }
            max_deques[j].push_back(right);

            while (max_deques[j].front() < left) {
                max_deques[j].pop_front();
            }

            current_max[j] = droids[max_deques[j].front()][j];
        }

        int total_shots = 0;
        for (int j = 0; j < m; ++j) {
            total_shots += current_max[j];
        }

        while (total_shots > k && left <= right) {
            left++;
            for (int j = 0; j < m; ++j) {
                while (!max_deques[j].empty() && max_deques[j].front() < left) {
                    max_deques[j].pop_front();
                }
                if (max_deques[j].empty()) {
                    current_max[j] = 0;
                }
                else {
                    current_max[j] = droids[max_deques[j].front()][j];
                }
            }
            total_shots = 0;
            for (int j = 0; j < m; ++j) {
                total_shots += current_max[j];
            }
        }

        if (right - left + 1 > max_length) {
            max_length = right - left + 1;
            for (int j = 0; j < m; ++j) {
                result[j] = current_max[j];
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        cout << result[j] << " ";
    }
    cout << endl;

    return 0;
}