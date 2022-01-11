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

set<int> dp[105];

int main() {
	set_io("");

    int n; cin >> n;

    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        coins.pb(x);
    }

    dp[0].insert(0);
    for (int i = 1; i <= coins.sz(); i++) {
        dp[i] = dp[i - 1];
        for (auto x : dp[i - 1]) 
            dp[i].insert(x + coins[i - 1]);
    }

    dp[coins.sz()].erase(dp[coins.sz()].begin());

    cout << dp[coins.sz()].sz() << endl;
    for (auto x : dp[coins.sz()])
        cout << x << " ";
    cout << endl;
}
