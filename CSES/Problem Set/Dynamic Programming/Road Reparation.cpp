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
    int w, a, b;
};

bool cmp(edge &v1, edge &v2) {
    return v1.w < v2.w;
}

int N, M, height[100005], parent[100005];
vector<edge> edges;

int find(int n) {
    if (n != parent[n]) parent[n] = find(parent[n]);
    return parent[n];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (height[a] < height[b]) swap(a, b);

    parent[b] = a;
    height[a] += (height[a] == height[b]);
}

int main() {
	set_io("");

    cin >> N >> M;
    edges.rsz(M);

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (auto &e : edges) cin >> e.a >> e.b >> e.w;
    sort(all(edges), cmp);

    ll ans = 0;
    bool valid = true;
    for (auto e : edges) {
        if (find(e.a) != find(e.b)) {
            ans += e.w;
            unite(e.a, e.b);
        }

        valid = true;
        for (int n = 1; n <= N; n++)
            if (find(e.a) != find(n)) {
                valid = false;
                break;
            }
        if (valid) break;
    }
    if (valid) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
}
