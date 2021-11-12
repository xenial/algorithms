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

vector<int> adj[2501];
bool visited[2501];
int parent[2501];

int main() {
    set_io("");

    int N, M; cin >> N >> M;

    int a, b;
    while (M--) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = INT_MAX - 1;

    queue<int> q;
    q.push(a);
    
    while(!q.empty()) {
        int c = q.front();
        q.pop();

        for (auto n : adj[c]) {
            if (visited[n] && parent[c] != n) {
                queue<int> qq;
 
                vector<int> depth(N + 1, INT_MAX - 1);
                vector<bool> vis(N + 1);

                depth[c] = 1;
                vis[c] = true;
                for (auto nn : adj[c]) 
                    if (nn != n) {
                        qq.push(nn);
                        depth[nn] = 2;
                        vis[nn] = true;
                    }

                while (!qq.empty()) {
                    int cc = qq.front();
                    qq.pop();

                    for (auto nn : adj[cc]) {
                        depth[nn] = min(depth[nn], depth[cc] + 1);

                        if (nn == n) ans = min(ans, depth[nn]);

                        if (!vis[nn]) {
                            qq.push(nn);
                            vis[nn] = true;
                        }
                    }
                }
            }

            if (!visited[n]) {
                q.push(n);
                visited[n] = true;
                parent[n] = c;
            }
        }
    }

    cout << (ans == INT_MAX - 1 ? -1 : ans) << endl;
}
