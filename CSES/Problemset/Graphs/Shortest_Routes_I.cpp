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

ll dist[100005];
bool visited[100005];

int main() {
    set_io("");

    fill_n(&dist[0], 100005, 1e18);

    int N, M; cin >> N >> M;
    vector<ii> adj[N + 1];

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    priority_queue<pair<ll,int>> q;
    q.push({0, 1});
    dist[1] = 0;

    while (!q.empty()) {
        auto c = q.top();
        q.pop();

        if (visited[c.se]) continue;
        visited[c.se] = true;

        for (auto n : adj[c.se]) {
            dist[n.fi] = min(-c.fi + n.se, dist[n.fi]);
            if (visited[n.fi]) continue;
            q.push({-dist[n.fi], n.fi});
        }
    }

    for (int i = 1; i <= N; i++) cout << dist[i] << " ";
    cout << endl;
}
