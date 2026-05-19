#include <iostream>
using namespace std;

bool checkastarbplus(string s) {
    int i = 0;
    int n = s.length();

    while (i < n && s[i] == 'a') {
        i++;
    }
    if (i >= n || s[i] != 'b') {
        return false;
    }
    while (i < n && s[i] == 'b') {
        i++;
    }
    return (i == n);
}

bool checkab(string s) {
    return (s.length() == 2 && s[0] == 'a' && s[1] == 'b');
}

bool isAccepted(string s) {
    if (checkastarbplus(s) || checkab(s)) {
        return true;
    }
    return false;
}

int main() {
    string testCases[5] = {
        "ab",
        "aab",
        "aaabbb",
        "b",
        "aba"
    };

    for (int i = 0; i < 5; i++) {
        cout << "String: " << testCases[i] << " -> ";

        if (isAccepted(testCases[i])) {
            cout << "ACCEPTED";
        } else {
            cout << "REJECTED";
        }

        cout << endl;
    }

    return 0;
}
