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
bool vis[100005], possible = true;
int team[100005];

void dfs(int n, int d = 0) {
    if (vis[n]) return;

    vis[n] = true;
    team[n] = 1 + d % 2;

    for (auto a : adj[n]) {
        if (team[a] == team[n]) {
            possible = false;
            return;
        }

        dfs(a, d + 1);
    }
}

int main() {
	set_io("");

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
        if (!possible) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) cout << team[i] << " ";
    cout << endl;
}
