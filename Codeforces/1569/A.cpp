#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

void solve(string s) {
    if (s.size() == 1) {
        cout <<"-1 -1" << endl;
        return;
    } else {
        char prev = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != prev) {
                cout << i << " " << i + 1 << endl;
                return;
            }
        }
        cout <<"-1 -1" << endl;
        return;
    }
}

int main() {
    set_io("");

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        solve(s);
    }
}