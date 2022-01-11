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

int dp[505][505];

int main() {
	set_io("");

    int a, b; cin >> a >> b;
    dp[1][1] = 0;

    for (int i = 2; i <= a; i++)
        dp[1][i] = dp[1][i - 1] + 1;

    for (int i = 2; i <= b; i++)
        dp[i][1] = dp[i - 1][1] + 1;

    for (int h = 2; h <= a; h++) {
        for (int w = 2; w <= b; w++) {
            if (h == w) {
                dp[w][h] = 0;
                continue;
            } else dp[w][h] = 1e9;
            
            for (int i = 1; i < max(w, h); i++) {
                if (w - i > 0) dp[w][h] = min(dp[w][h], dp[w - i][h] + dp[i][h] + 1);
                if (h - i > 0) dp[w][h] = min(dp[w][h], dp[w][h - i] + dp[w][i] + 1);
            }
        }
    }

    cout << dp[b][a] << endl;
}
