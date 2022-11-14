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

int N, depth[200005];
bool pelto[200005], vis[200005];
ll dist[200005];

int main() {
	set_io("");

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> pelto[i];

    vector<vector<ii>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb(ii(b, w));
        adj[b].pb(ii(a, w));
    }

    vector<ii> dl;
    stack<ii> s;
    s.push(ii(1, 0));
    while (!s.empty()) {
        auto [cur, d] = s.top();
        s.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        dl.pb(ii(d, cur));
        depth[cur] = d;

        for (auto n : adj[cur]) {
            if (vis[n.fi]) continue;

            s.push(ii(n.fi, d + 1));
        }
    }

    sort(all(dl), greater());

    for (auto n : dl) {
        int cn = n.se;

        dist[cn] = LLONG_MAX;

        if (!pelto[cn]) {
            dist[cn] = 0;
            continue;
        }

        for (auto a : adj[cn]) {
            if (depth[a.fi] < n.fi || dist[a.fi] == LLONG_MAX) continue;

            dist[cn] = min(dist[cn], dist[a.fi] + a.se);
        }

    }

    sort(all(dl));

    for (auto n : dl) {
        int cn = n.se;

        for (auto a : adj[cn]) {
            if (depth[a.fi] > n.fi) continue;

            dist[cn] = min(dist[cn], dist[a.fi] + a.se);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) ans += dist[i];
    cout << ans << endl;
}
