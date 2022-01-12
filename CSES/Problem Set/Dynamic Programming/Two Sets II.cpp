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

unsigned int dp[130000][505];
int mod = 1e9 + 7;

int main() {
	set_io("");

    int n; cin >> n;
    int t = (n * (1 + n) / 2);
    if (t % 2) {
        cout << 0 << endl;
        return 0;
    }
    t /= 2;

    for (int i = 0; i <= n; i++) dp[0][i] = 1;

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] += dp[i][j - 1];
            if (i - j >= 0) dp[i][j] += dp[i - j][j - 1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[t][n - 1] << endl;
}
