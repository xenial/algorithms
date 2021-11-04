#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

ll n, x, y;

bool printable(ll t) {
    ll count = 1;
    t -= min(x, y);
    if (t < 0) return false;
    count += (t / x) + (t / y);
    return count >= n;
}

int main() {
    set_io("");

    cin >> n >> x >> y;
    ll l = 0, r = 2e9;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (printable(m)) r = m;
        else l = m;
    }
    cout << r;
}