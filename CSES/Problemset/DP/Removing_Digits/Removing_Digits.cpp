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
    vector<int> dp(n + 1, 1e7);

    dp[n] = 0;
    for (int i = 0; i <= n; i++) 
        for (int j = 0, e = 1; n % e != n; j++, e = (int)pow(10, j)) {
            int p = n - i, d = (p / e) % 10;
            if (p - d >= 0) dp[p - d] = min(dp[p - d], dp[p] + 1);
        }
    cout << dp[0];
}
