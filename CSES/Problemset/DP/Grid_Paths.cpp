#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

const int mod = 1e9 + 7;

int main() {
    set_io("");

    int n; cin >> n;
    vector<pair<char, int>> prev(n), cur(n);
    cin >> prev[0].fi;
    prev[0].se = prev[0].fi != '*';

    for (int x = 1; x < n; x++) {
        cin >> prev[x].fi;
        prev[x].se = prev[x].fi == '*' ? 0 : prev[x - 1].se;
    }

    for (int y = 1; y < n; y++) {
        cin >> cur[0].fi;
        cur[0].se = cur[0].fi == '*' ? 0 : prev[0].se;

        for (int x = 1; x < n; x++) {
            cin >> cur[x].fi;
            cur[x].se = cur[x].fi == '*' ? 0 : (cur[x - 1].se + prev[x].se) % mod;
        }

        prev = cur;
    }

    cout << (n > 1 ? cur[n - 1].se : prev[0].se);
}
