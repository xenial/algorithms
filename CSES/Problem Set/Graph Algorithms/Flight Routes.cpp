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

int N, M, K;
vector<vector<ll>> dist;
vector<vector<ii>> adj;

int main() {
	set_io("");
    
    cin >> N >> M >> K;

    adj.rsz(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({c, b});
    }

    dist = vector<vector<ll>>(N + 1, vector<ll>(K, LLONG_MAX));

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dist[1][0] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        ll cc = q.top().fi;
        int cn = q.top().se;
        q.pop();

        if (cc > dist[cn][K - 1]) continue;

        for (auto e : adj[cn]) {
            if (dist[e.se][K - 1] > cc + e.fi) {
                dist[e.se][K - 1] = cc + e.fi;
                sort(all(dist[e.se]));
                q.push({cc + e.fi, e.se});
            }
        }
    }

    for (auto &c : dist[N]) cout << c << " ";
    cout << endl;
}
