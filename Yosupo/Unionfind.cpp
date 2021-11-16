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

int parent[200002], height[200002];

int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}

void unite(int a, int b) {
    if (height[a] < height[b]) swap(a, b);

    int ra = find(a), rb = find(b);
    parent[rb] = ra;
    height[ra] = max(height[ra], height[rb] + 1);
}

int main() {
    set_io("");

    int N, Q; cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        height[i] = 1;
    }

    while (Q--) {
        bool t; cin >> t;
        int u, v; cin >> u >> v;

        if (!t) {
            unite(u, v);
        } else {
            cout << (find(u) == find(v)) << endl;
        }
    }
}
