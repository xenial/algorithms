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
vector<bool> visited;

int dfs(int n) {
    int ans = 1;
    visited[n] = true;
    for (auto e : adj[n]) if (!visited[e]) ans += dfs(e);
    return ans;
}

int main() {
    set_io("moocast");

    int n; cin >> n;
    vector<tuple<int,int,int>> cows(n);
    adj.rsz(n);
    for (int i = 0; i < n; i++) cin >> get<0>(cows[i]) >> get<1>(cows[i]) >> get<2>(cows[i]);

    for (int i = 0; i < cows.sz(); i++) {
        for (int j = 0; j < cows.sz(); j++) {
            if (j == i) continue;
            int dist = sqrt(pow(abs(get<0>(cows[i]) - get<0>(cows[j])), 2) + pow(abs(get<1>(cows[i]) - get<1>(cows[j])), 2));
            if (dist < get<2>(cows[i])) adj[i].pb(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        visited = vector<bool>(n, false);
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}