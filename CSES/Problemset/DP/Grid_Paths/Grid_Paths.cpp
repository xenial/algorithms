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
    char grid[n][n];
    int dp[n][n];

    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++) {
            dp[x][y] = 0;
            cin >> grid[x][y];
        }

    dp[0][0] = 1;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++) {
            if ((!y && !x) || (grid[x][y - 1] == '*' && grid[x - 1][y] == '*') || (grid[x][y] == '*')) continue;
            else if (!y || grid[x][y - 1] == '*') dp[x][y] = dp[x - 1][y];
            else if (!x || grid[x - 1][y] == '*') dp[x][y] = dp[x][y - 1];
            else dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
        } 
    cout << dp[n - 1][n - 1];
}
