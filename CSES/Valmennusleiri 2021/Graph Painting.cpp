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

int main() {
    set_io("");
	
	srand(time(0));
	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		for (int i = 0; i < m; i++) {	
			int a, b; cin >> a >> b;
			adj[a].pb(b);
		}

		string ans(n + 1, 'R');
		int count = 0;
		while (count < m / 2) {
			for (int i = 1; i < adj.sz(); i++) {
				auto a = adj[i];
				if (a.sz() == 0) continue;
				for (auto n : a) {
					ans[i] = rand() % 2 ? 'R' : 'B';
					ans[n] = rand() % 2 ? 'R' : 'B';
				}	
			}
			
			count = 0;
			for (int i = 1; i < adj.sz(); i++) {
				auto a = adj[i];
				for (auto n : a)
					if (ans[i] != ans[n]) count++;
			}
		}

		for (int i = 1; i < ans.sz(); i++) cout << ans[i] << " ";
		cout << endl;
	}


}
