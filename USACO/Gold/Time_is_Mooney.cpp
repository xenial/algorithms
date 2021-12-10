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

int money[1005];
vector<ii> edges;
int N, M, C;

int main() {
	set_io("time");

	cin >> N >> M >> C;

	for (int i = 1; i <= N; i++) cin >> money[i];
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		edges.pb({a, b});
	}

	vector<vector<ll>> dp(1005, vector<ll>(2005, -1));
	
	ll maxpoints = 0;
	dp[1][0] = 0;
	for (int i = 1; i < 2000; i++) {
		for (auto e : edges) {
			auto [a, b] = e;
			if (dp[a][i - 1] != -1) {
				dp[b][i] = max(dp[b][i], dp[a][i - 1] + money[b]);
			}
			if (b == 1) maxpoints = max(maxpoints, dp[b][i] - C * i * i);
		}
	}
	cout << maxpoints << endl;
}
