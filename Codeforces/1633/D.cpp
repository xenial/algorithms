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

int main() {
	set_io("");

    int T; cin >> T;

    vector<set<int>> adj(1005);
    for (int i = 1; i < 1005; i++) 
        for (int j = 1; j <= i; j++)
            if (i + i / j < 1005)
                adj[i].insert(i + i / j);

    vi md(1005, INT_MAX);
    md[1] = 0;
    vector<bool> vis(1005);

    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, 1});

    while (!q.empty()) {
        auto [d, c] = q.top();
        q.pop();

        if (md[c] < d || vis[c]) continue;
        vis[c] = true;

        for (auto a : adj[c]) {
            if (md[a] > d + 1 && !vis[a]) {
                md[a] = d + 1;
                q.push({d + 1, a});
            }
        }
    }

    while (T--) {
        int N, K;
        cin >> N >> K;

        vi b(N + 1), c(N + 1), cost(N + 1);
        for (int i = 1; i <= N; i++) cin >> b[i];
        for (int i = 1; i <= N; i++) cin >> c[i];

        for (int i = 1; i <= N; i++)
            cost[i] = md[b[i]];

        K = min(K, 12 * N);
        vi dp(K + 5);

        for (int i = 1; i <= N; i++)
            for (int j = K; j >= 0; j--) 
                if (j - cost[i] >= 0) 
                    dp[j] = max(dp[j], dp[j - cost[i]] + c[i]);

        cout << dp[K] << endl;
    }
}
