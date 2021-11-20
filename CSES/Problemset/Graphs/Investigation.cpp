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

ll price[100005], routes[100005];
int mod = 1e9 + 7, minflights[100005], maxflights[100005];
bool visited[100005];

int main() {
    set_io("");

    fill_n(&price[0], 100005, 1e18);
    fill_n(&minflights[0], 100005, 1e9);

    int N, M; cin >> N >> M;
    vector<ii> adj[N + 1];

    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    priority_queue<pair<ll, int>> q;
    q.push({0, 1});
    routes[1] = 1;
    minflights[1] = maxflights[1] = price[1] = 0;

    while (!q.empty()) {
        auto c = q.top();    
        q.pop();

        ll cp = -c.fi;
        int cn = c.se;

        if (visited[cn]) continue;
        visited[cn] = true;

        for (auto n : adj[cn]) {
            if (price[n.fi] >= price[cn] + n.se) { 
                if (price[n.fi] == price[cn] + n.se) {
                    minflights[n.fi] = min(minflights[n.fi], minflights[cn] + 1);
                    maxflights[n.fi] = max(maxflights[n.fi], maxflights[cn] + 1);
                    routes[n.fi] = (routes[n.fi] + routes[cn] % mod) % mod;
                } else {
                    minflights[n.fi] = minflights[cn] + 1;
                    maxflights[n.fi] = maxflights[cn] + 1;
                    routes[n.fi] = routes[cn];
                }

                price[n.fi] = price[cn] + n.se;
            }

            q.push({-price[n.fi], n.fi});
        }
    }

    cout << price[N] << " " << routes[N] << " " << minflights[N] << " " << maxflights[N] << endl;
}
