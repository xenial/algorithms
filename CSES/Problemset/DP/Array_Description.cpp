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

int mod = 1e9 + 7;
vector<int> d{-1, 0, 1};
ll dp[100005][105];
int main() {
    set_io("");

    int N, M; cin >> N >> M;

    int n; cin >> n;
    if (n) dp[0][n] = 1;
    else for (int i = 1; i <= M; i++) dp[0][i] = 1;

    for (int i = 1; i < N; i++) {
        int n; cin >> n;

        if (n) for (auto x : d) {
            int nn = n + x;
            if (nn >= 0 || nn <= M)
                dp[i][n] = (dp[i][n] + dp[i - 1][nn]) % mod;
        }
        else for (int j = 1; j <= M; j++) 
            for (auto x : d) {
                int nn = j + x;
                if (nn >= 0 || nn <= M) dp[i][j] = (dp[i][j] + dp[i - 1][nn]) % mod;
            }
    }

    ll ans = 0;
    for (int i = 1; i <= M; i++) ans += dp[N - 1][i];
    cout << ans % mod << endl;
}
