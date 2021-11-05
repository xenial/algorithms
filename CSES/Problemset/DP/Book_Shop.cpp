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

    vector<pair<int,int>> books(n);
    vector<pair<int, vector<int>>> dp(x + 1);

    dp[0].fi = 0;
    for (int i = 0; i < n; i++) dp[0].se.pb(i);

    for (int i = 0; i < n; i++) cin >> books[i].fi;
    for (int i = 0; i < n; i++) cin >> books[i].se;

    int ans = 0;
    for (int i = 0; i <= x; i++) {
        for (auto b : dp[i].se) {
            if (i + books[b].fi <= x && dp[i].fi + books[b].se >= dp[i + books[b].fi].fi) {
                dp[i + books[b].fi].fi = dp[i].fi + books[b].se;
                dp[i + books[b].fi].se = dp[i].se;
                if (dp[i].fi != dp[i + books[b].fi].fi)
                    dp[i + books[b].fi].se.erase(lower_bound(all(dp[i + books[b].fi].se), b));
            }
        }
        ans = max(ans, dp[i].fi);
    }

    cout << ans;
}
