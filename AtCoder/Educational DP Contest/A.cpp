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

    int n; cin >> n;

    int stones[n];
    for (int i = 0; i < n; i++) cin >> stones[i];
    
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (i + 1 <= n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(stones[i] - stones[i + 1]));
        if (i + 2 <= n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(stones[i] - stones[i + 2]));
    }
    cout << dp[n - 1];
}