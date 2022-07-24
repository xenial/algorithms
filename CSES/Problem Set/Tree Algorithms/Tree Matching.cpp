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

int N, parent[200005];
bool matched[200005];
vvi adj;
priority_queue<ii> depth;

void dfs(int cn, int p, int d) {
    for (auto n : adj[cn]) {
        if (n != p) {
            parent[n] = cn;
            depth.push(ii(d + 1, n));
            dfs(n, cn, d + 1);
        }
    }
}

int main() {
	set_io("");

    cin >> N;

    adj.rsz(N + 5);
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    depth.push(ii(0, 1));
    parent[1] = 0;
    dfs(1, 0, 0);

    int ans = 0;

    while (!depth.empty()) {
        ii cur = depth.top();
        depth.pop();

        if (cur.se == 1) continue;

        if (!matched[cur.se] && !matched[parent[cur.se]]) {
            matched[cur.se] = matched[parent[cur.se]] = true;
            ans++;
        }
    }

    cout << ans << endl;
}
