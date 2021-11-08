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

int main() {
    set_io("");

    int n, x; cin >> n >> x;

    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int b = 0; b < n; b++) {
        for (int m = 0; m <= x; m++) {
            dp[b + 1][m] = dp[b][m];
            if (m - prices[b] >= 0) dp[b + 1][m] = max(dp[b + 1][m], dp[b][m - prices[b]] + pages[b]);
        }
    }
    cout << dp[n][x];
}