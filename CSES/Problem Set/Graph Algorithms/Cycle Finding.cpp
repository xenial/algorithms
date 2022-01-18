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

struct edge {
    int a, b, w;
};

int N, M;
vector<edge> edges;
ll dist[100005];
int parent[100005];

int main() {
	set_io("");

    cin >> N >> M;
    edges.rsz(M);

    for (auto &e : edges) cin >> e.a >> e.b >> e.w;

    int x;
    for (int i = 0; i < N; i++) {
        x = 0;

        for (auto e : edges) {
            if (dist[e.b] > dist[e.a] + e.w) {
                x = e.b;
                parent[e.b] = e.a;
                dist[e.b] = dist[e.a] + e.w;
            }
        }
    }

    if (x) {
        for (int i = 0; i < N; i++) x = parent[x];

        vector<int> ans;
        int s = x;
        ans.pb(s);
        x = parent[x];
        while (x != s) {
            ans.pb(x);
            x = parent[x];
        }
        ans.pb(s);
        reverse(all(ans));

        cout << "YES" << endl;
        for (auto n : ans) cout << n << " ";
        cout << endl;
    } else cout << "NO" << endl;
}
