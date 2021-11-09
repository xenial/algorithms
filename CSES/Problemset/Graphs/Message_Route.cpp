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

bool visited[100001];
int depth[100001];
int parent[100001];

int main() {
    set_io("");

    fill_n(depth, 100001, INT_MAX);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    while (M--) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int> q;

    q.push(1);
    visited[1] = true;
    depth[1] = 1;

    while (!q.empty()) {
        int cn = q.front();
        q.pop();

        for (auto n : adj[cn]) {
            if (depth[cn] + 1 < depth[n]) {
                depth[n] = depth[cn] + 1;
                parent[n] = cn;
            }

            if (!visited[n]) { 
                q.push(n);
                visited[n] = true;
            }
        }
    }

    if (visited[N]) {
        cout << depth[N] << endl;
        stack<int> n;
        n.push(N);
        while (n.top() != 1) n.push(parent[n.top()]);
        while (!n.empty()) {
            cout << n.top() << " ";
            n.pop();
        }
    } 
    else cout << "IMPOSSIBLE";
}
