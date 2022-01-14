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
 
vector<vector<int>> adj(100005);
int parent[100005];
bool vis[100005];
int sn, en;
 
bool dfs(int n, int p) {
    vis[n] = true;
    parent[n] = p;

    for (auto a : adj[n]) {
        if (a == p) continue;
        else if (vis[a]) {
            sn = a;
            en = n;
            return true;
        } else if (!vis[a])
            if (dfs(a, n)) return true;
    }
    return false;
}
 
int main() {
	set_io("");
 
    int n, m; cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);;
    }
 
    for (int i = 1; i <= n; i++) {
        if (vis[i] || !dfs(i, -1)) continue;

        vector<int> ans(1, sn);
        while (en != parent[sn]) {
            ans.pb(en);
            en = parent[en];
        }
        cout << ans.sz() << endl;
        for (auto n : ans) cout << n << " ";
        cout << endl;
        return 0;
    }

    cout << "IMPOSSIBLE" << endl;
}