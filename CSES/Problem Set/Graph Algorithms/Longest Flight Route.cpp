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

int N, M, id[100005], dist[100005], parent[100005];
vvi adj, in;
queue<int> q;
vector<int> top;

int main() {
	set_io("");

    cin >> N >> M;

    adj.rsz(N + 1);
    in.rsz(N + 1);

    fill_n(&dist[0], 100005, -1e9);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        in[b].pb(a);
        id[b]++;
    }

    for (int i = 1; i <= N; i++)
        if (!id[i]) q.push(i);

    dist[1] = 0;
    bool s = false;
    while (!q.empty()) {
        int cn = q.front();
        top.pb(cn);
        q.pop();

        for (auto n : adj[cn]) {
            id[n]--;
            if (!id[n]) q.push(n);
        }

        for (auto n : in[cn]) {
            if (dist[cn] < dist[n] + 1) {
                dist[cn] = dist[n] + 1;
                parent[cn] = n;
            }
        }
    }

    if (dist[N] < 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    parent[1] = 0;
    int x = N;
    vi ans;

    while (x != 0) {
        ans.pb(x);
        x = parent[x];
    }

    reverse(all(ans));

    cout << ans.sz() << endl;
    for (auto &n : ans) cout << n << " ";
    cout << endl;
}
