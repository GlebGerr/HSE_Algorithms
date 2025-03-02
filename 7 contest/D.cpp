#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isGoodSubstring(const vector<int>& count) {
    for (int i = 0; i < 26; ++i) {
        if (count[i] != 1) {
            return false;
        }
    }
    return true;
}

string findGoodWord(const string& s) {
    int n = s.length();
    if (n < 26) {
        return "-1";
    }

    vector<int> count(26, 0);
    int questionMarks = 0;

    for (int i = 0; i < 26; ++i) {
        if (s[i] == '?') {
            questionMarks++;
        }
        else {
            count[s[i] - 'A']++;
        }
    }

    for (int i = 26; i <= n; ++i) {
        bool canForm = true;
        int missing = 0;
        for (int j = 0; j < 26; ++j) {
            if (count[j] > 1) {
                canForm = false;
                break;
            }
            if (count[j] == 0) {
                missing++;
            }
        }

        if (canForm && missing == questionMarks) {
            string result = s;
            vector<char> missingLetters;
            for (int j = 0; j < 26; ++j) {
                if (count[j] == 0) {
                    missingLetters.push_back('A' + j);
                }
            }

            int idx = 0;
            for (int j = i - 26; j < i; ++j) {
                if (result[j] == '?') {
                    result[j] = missingLetters[idx++];
                }
            }

            for (char& c : result) {
                if (c == '?') {
                    c = 'A';
                }
            }

            return result;
        }

        if (i < n) {
            if (s[i - 26] == '?') {
                questionMarks--;
            }
            else {
                count[s[i - 26] - 'A']--;
            }

            if (s[i] == '?') {
                questionMarks++;
            }
            else {
                count[s[i] - 'A']++;
            }
        }
    }

    return "-1";
}

int main() {
    string s;
    cin >> s;
    string result = findGoodWord(s);
    cout << result << endl;
    return 0;
}