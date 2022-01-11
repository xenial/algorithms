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

vector<vector<int>> adj;

bool can_reach(int s, int d, vector<bool> &visited) {
    visited[s] = true;
    for (auto e : adj[s]) if (!visited[e]) {
        if (e == d || can_reach(e, d, visited)) return true;
    }
    return false;
}

int reach_all(int n, vector<bool> &visited) {
    visited[n] = true;
    for (auto e : adj[n]) if (!visited[e]) reach_all(e, visited);
    for (int i = 0; i < visited.sz(); i++) if (!visited[i]) return i;
    return -1;
}

int main() {
    set_io("");

    int n, m; cin >> n >> m;
    adj.rsz(n);
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b-1);
    }

    vector<bool> visited(n, false);
    int ra = reach_all(0, visited);
    if (ra != -1) {
        cout << "NO" << endl << 1 << " " << ra+1;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        visited = vector<bool>(n, false);
        if (!can_reach(i, 0, visited)) {
            cout << "NO" << endl << i+1 << " " << 1;
            return 0;
        }
    }
    cout << "YES";
}