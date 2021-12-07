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

	int n; cin >> n;

	vector<ii> in;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		in.pb({x, y});
	}
	
	vector<ii> corners;
	bool px, py;
	for (auto n : in) {
		for (auto nn : in) {
			if (n.fi != nn.fi && n.se != nn.se) {
				corners.pb(n);
				corners.pb(nn);
				break;
			}
		}
		if (corners.sz() == 2) break;
	}

	if (corners.sz() != 2 || corners.sz() == 0) {
		cout << -1 << endl;
		return 0;
	}

	int xd = abs(corners[0].fi - corners[1].fi);
	int yd = abs(corners[0].se - corners[1].se);

	cout << xd * yd << endl;
}
