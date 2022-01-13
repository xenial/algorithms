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

int mP(int x, int e, int mod) {
    if (e == 0) return 1;
    ll ans = mP(x, e / 2, mod);
    ans = (ans * ans) % mod;
    if (e % 2 == 1) ans = (ans * x) % mod;
    return ans;
}

int main() {
	set_io("");

    int n; cin >> n;

    while (n--) {
        int x, e; cin >> x >> e;
        cout << mP(x, e, 1e9 + 7) << endl;
    }
}
