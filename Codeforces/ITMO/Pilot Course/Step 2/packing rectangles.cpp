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

ll w, h, n;

bool fits(ll x) {
    return (x / w) * (x / h) >= n;
}

int main() {
    set_io("");

    cin >> w >> h >> n;
    ll l = 0, r = 1;
    while (!fits(r)) r *= 2;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (fits(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}