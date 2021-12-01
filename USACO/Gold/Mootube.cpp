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

int parent[100005], height[100005], Size[100005];

int find(int n) {
	if (n != parent[n]) parent[n] = find(parent[n]);
	return parent[n];
}

void unite(int a, int b) {
	if (height[a] < height[b]) swap(a, b);

	height[a] = height[a] == height[b] ? height[a] + 1 : height[a];
	int ra = find(a), rb = find(b);
	parent[rb] = ra;
	Size[ra] += Size[rb];
}

bool cmp(pair<ii,int> &a, pair<ii,int> &b) {
	return a.se < b.se;
}

int main() {
    set_io("mootube");
	
	int N, Q; cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = Size[i] = 1;
	}

	vector<pair<int, ii>> edges(N - 1);
	for (int i = 1; i <= N - 1; i++) {
		int p, q, r; cin >> p >> q >> r;
		edges.pb({r, {p, q}});
	}
	sort(all(edges), greater<>());
	
	vector<pair<ii, int>> queries(Q);
	for (int i = 0; i < Q; i++) {
		int k, v; cin >> k >> v;
		queries[i] = {{k, v}, i};
	}
	sort(all(queries), greater<>());
	
	vector<int> ans(Q);
	int i = 0;
	for (auto query : queries) {
		while (i < edges.sz() && query.fi.fi <= edges[i].fi) {
			unite(edges[i].se.fi, edges[i].se.se);
			i++;
		}
		ans[query.se] = Size[find(query.fi.se)] - 1;
	}

	for (auto a : ans) cout << a << "\n";
}
