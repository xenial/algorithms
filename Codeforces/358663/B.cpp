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

int t[200005];

int main() {
    set_io("");
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i];

	ll ans = 0, prev = 0;
	for (int i = 0; i < n; i++) {
		ll cur = prev;
		ll diff = t[i] - cur;
		ans += abs(diff);
		prev = cur + diff;
	}

	cout << ans << endl;
}
