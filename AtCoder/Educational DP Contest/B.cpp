#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int dp[100005];
vi stones;

int main() {
    set_io("");

    int N, K;
    cin >> N >> K;

    stones.rsz(N);
    for (auto &s : stones) cin >> s;

    fill_n(&dp[0], 100005, 1e9);
    dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i - j >= 0)
                dp[i] = min(dp[i], dp[i - j] + abs(stones[i] - stones[i - j]));
            else
                break;
        }
    }

    cout << dp[N - 1] << endl;
}
