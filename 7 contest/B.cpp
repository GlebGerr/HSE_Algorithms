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

    // Сортируем друзей по количеству денег
    sort(friends.begin(), friends.end());

    long long max_friendship = 0;
    long long current_friendship = 0;
    int left = 0;

    // Используем метод двух указателей
    for (int right = 0; right < n; ++right) {
        // Добавляем текущего друга в окно
        current_friendship += friends[right].second;

        // Пока разница между крайними друзьями в окне больше d, сдвигаем левый указатель
        while (friends[right].first - friends[left].first >= d) {
            current_friendship -= friends[left].second;
            left++;
        }

        // Обновляем максимальную сумму
        max_friendship = max(max_friendship, current_friendship);
    }

    cout << max_friendship << endl;

    return 0;
}