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

int w[100005];

bool cmp(ii p1, ii p2) {
	return p2.fi >= p1.fi && p2.se >= p1.se;
}

int sv(ii p) {
	return p.se - p.fi;
}

int main() {
    set_io("");

	int n; cin >> n;
	vector<ii> points(n);
 	for (int i = 0; i < n; i++) cin >> points[i].fi >> points[i].se;
	for (int i = 0; i < n; i++) cin >> w[i];
	
	sort(all(points), cmp);
	
	vector<vector<int>> sp;
	set<int> buf;
	for (int i = 0; i < n - 1; i++) {
		ii p1 = points[i], p2 = points[i + 1];
		if (!cmp(p1, p2)) {
			buf.insert(i);
			buf.insert(i + 1);
		} else {
			if (buf.sz() > 0) sp.pb(vector<int>(all(buf)));
			buf = set<int>();
		}
	}
	if (buf.sz() > 0) sp.pb(vector<int>(all(buf)));
	
	bool possible = true;
	for (auto spg : sp) {
		for (auto n : spg) {
			bool b = false;
			for (auto nn : spg) {
				if (sv(points[n]) == w[nn]) b = true;
			}
			if (!b) possible = false;
		}
	}

	cout << possible << endl;
}
