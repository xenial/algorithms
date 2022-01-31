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

ll div_ceil(ll x, ll y) {
    return x / y + (x % y > 0);
}

int main() {
	set_io("");

    int T; cin >> T;

    while (T--) {
        ll ch, ca; cin >> ch >> ca;
        ll mh, ma; cin >> mh >> ma;
        ll k, w, a; cin >> k >> w >> a;

        bool possible = false;
        for (ll i = 0; i <= k; i++) {
            ll rtk = div_ceil(mh, (ca + i * w)),
            rtd = div_ceil((ch + (k - i) * a), ma);
            if (rtk <= rtd) {
                possible = true;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
}
