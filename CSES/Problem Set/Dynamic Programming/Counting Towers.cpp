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

unsigned int dp[1000005][2];
int mod = 1e9 + 7;

int main() {
	set_io("");

    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < 1000005; i++) {
        dp[i][0] = (dp[i - 1][0] * 4 % mod + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 1][1] * 2 % mod + dp[i - 1][0]) % mod;
    }


    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;
    }
}
