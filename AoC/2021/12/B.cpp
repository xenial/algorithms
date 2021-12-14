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

map<string, vector<string>> adj;

map<string, bool> mem;
bool large(string s) {
	if (mem[s]) return mem[s];
	bool ans = true;
	for (auto c : s) if (!isupper(c)) ans = false;
	return mem[s] = ans;
}

int dfs(string cc = "start", map<string, bool> vis = map<string, bool>(), bool t = false) {
	vis[cc] = true;
	
	int ans = 0;
	for (auto n : adj[cc]) {
		if (n == "end") ans += 1;
		else if (large(n)) ans += dfs(n, vis, t);
		else if (!vis[n]) ans += dfs(n, vis, t);
		else if (!t && vis[n] && n != "start") ans += dfs(n, vis, true);
	}
	return ans;
}

int main() {
	set_io("");

	for (int i = 0; i < 24; i++) {
		string a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	cout << dfs() << endl;
}
