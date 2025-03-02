#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> freq;
    long long result = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        freq[a[right]]++;
        while (freq[a[right]] >= k) {
            result += n - right;
            freq[a[left]]--;
            left++;
        }
    }

    cout << result << endl;

    return 0;
}