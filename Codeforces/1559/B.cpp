#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    bool empty = true;
    string r = s;

    for (auto c : s) {
        if (c != '?') {
            empty = false;
            break;
        }
    }

    if (empty) {
        r[0] = 'B';
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '?') {
            if (r[i - 1] != '?')
                r[i] = r[i - 1] == 'R' ? 'B' : 'R';
        }
    }

    for (int i = s.size() - 2; i >= 0; i--) {
        if (s[i] == '?') {
            if (r[i + 1] != '?')
                r[i] = r[i + 1] == 'R' ? 'B' : 'R';
        }
    }

    return r;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t, n;
    string s;

    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << solve(s) << endl;
    }
}