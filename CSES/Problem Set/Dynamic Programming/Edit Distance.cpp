#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize
#define ii pair<int,int>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int dp[5005][5005];

int main() {
	set_io("");

    string s, t; cin >> s >> t;

    dp[0][0] = 0;

    for (int x = 1; x <= s.sz(); x++) dp[x][0] = dp[x - 1][0] + 1;
    for (int y = 1; y <= t.sz(); y++) dp[0][y] = dp[0][y - 1] + 1;

    for (int y = 1; y <= t.sz(); y++)
        for (int x = 1; x <= s.sz(); x++) {
            dp[x][y] = min({dp[x - 1][y] + 1, dp[x][y - 1] + 1,
                            dp[x - 1][y - 1] + (s[x - 1] != t[y - 1])});
        }

    cout << dp[s.sz()][t.sz()] << endl;
}
