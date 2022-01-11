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

    int n, x; cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++) 
        for (auto coin : coins)
            if (i - coin >= 0) {
                dp[i] += dp[i - coin];
                dp[i] %= mod;
            }
    
    cout << dp[x];
}