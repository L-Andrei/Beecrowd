#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve(int caso) {
    int x;
    cin >> x;

    if (x % 1111 == 0) {
        cout << "Caso #" << caso << ": -1\n";
        return;
    }

    int cnt = 0;
    while (x != 6174) {
        string s = to_string(x);
        s = string(4 - s.length(), '0') + s;

        string menor_str = s;
        sort(menor_str.begin(), menor_str.end());

        string maior_str = s;
        sort(maior_str.rbegin(), maior_str.rend());

        x = stoi(maior_str) - stoi(menor_str);
        cnt++;
    }

    cout << "Caso #" << caso << ": " << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; ++i) {
            solve(i);
        }
    }
    return 0;
}