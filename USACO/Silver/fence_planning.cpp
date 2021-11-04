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

typedef pair<int,int> point;
vector<point> cows;
vector<vector<int>> adj;
vector<bool> visited;
pair<point,point> dims;

void dfs(int n) {
    visited[n] = true;
    dims.fi.fi = min(dims.fi.fi, cows[n].fi);
    dims.fi.se = min(dims.fi.se, cows[n].se);
    dims.se.fi = max(dims.se.fi, cows[n].fi);
    dims.se.se = max(dims.se.se, cows[n].se);

    for (auto e : adj[n]) if (!visited[e]) dfs(e);
}

int main() {
    set_io("");

    int n, m; cin >> n >> m;
    cows.rsz(n);
    adj.rsz(n);
    visited.rsz(n);
    for (int i = 0; i < n; i++) cin >> cows[i].fi >> cows[i].se;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    
    int ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dims = pair<point,point>{{INT_MAX, INT_MAX}, {INT_MIN, INT_MIN}};
            dfs(i);
            ans = min(ans, 2*((dims.se.fi - dims.fi.fi) + (dims.se.se - dims.fi.se)));
        }
    }
    cout << ans;
}