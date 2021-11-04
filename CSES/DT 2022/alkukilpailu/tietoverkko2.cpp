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

const int MX = 200001;

vector<pair<int, pair<int, int>>> edges;
int parent[MX], Size[MX];

bool cmp(pair<int, pair<int, int>> v1, pair<int, pair<int, int>> v2) {
    return v1.fi > v2.fi;
}

int Find(int n) {
    while (parent[n] != n) n = parent[n];
    return n;
}

void unite(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (Size[a] < Size[b]) swap(a, b);
    Size[a] += Size[b];
    parent[b] = a;
}

int main() {
    set_io();

    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, x; cin >> a >> b >> x;
        edges.pb({x, {a-1, b-1}});
    }
    sort(all(edges), cmp);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        Size[i] = 1;
    }

    ll ans = 0;
    for (auto edge : edges) {
        int a = Find(edge.se.fi), b = Find(edge.se.se);
        ans += (ll)edge.fi * (Size[a] * Size[b]);
        unite(a, b);
    }
    cout << ans;
}