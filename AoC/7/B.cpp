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

ll fc[10000];
vector<int> in(1000);

ll tfc(int p) {
	ll ans = 0;
	for (auto n : in) ans += fc[abs(n - p)];
	return ans;
}

int main() {
    set_io("/home/xenial/Workspace/algorithms/AoC/7/x");

	for (int i = 0; i < 1000; i++) cin >> in[i];

	fc[1] = 1;
	for (int i = 2; i < 10000; i++) 
		fc[i] = fc[i - 1] + fc[i - 1] - fc[i - 2] + 1;
	
	ll prev = tfc(0);
	for (int i = 1; i < 10000; i++) {
		ll cfc = tfc(i);
		if (prev <= cfc) break;
		prev = cfc;
	}

	cout << prev << endl;
}
