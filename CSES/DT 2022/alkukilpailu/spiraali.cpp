#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize

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

    ll n, t; cin >> n >> t; 
    ll mid = n / 2;
    
    while (t--) {
        ll y, x; cin >> y >> x;
        ll xdist = n - x + 1;
        ll ydist = n - y + 1;
        ll ring = 4 * (n - 1), rindex = min(min(x, xdist), min(y, ydist)), dx, dy, offset;

        if (x <= mid) {
            if (y <= mid) {
                dx = x - min(x, y) + 1; dy = y - min(x, y) + 1;
                if (dx != 1) offset = -8;
                else offset = 0;
            } else {
                offset = -2;
                dx = x - min(x, ydist) + 1; dy = y + min(x, ydist) - 1;
            }
        } else {
            if (y <= mid) {
                offset = -6;
                dx = x + min(xdist, y) - 1; dy = y - min(xdist, y) + 1;
            } else {
                offset = -4;
                dx = x + min(xdist, ydist) - 1; dy = y + min(xdist, ydist) - 1;
            }
        }

        ll start;
        if (dx == 1) {
            start = dy;
        } else if (dx == n) {
            start = 2 * n + n - 1 - dy;
        } else if (dy == 1) {
            start = ring + 2 - dx;
        } else if (dy == n) {
            start = n - 1 + dx;
        }

        ll base = ring + offset;
        ll ans = start;
        ans += (rindex - 1) * (base + base - (rindex - 2) * 8) / 2;

        cout << ans << endl;
    }
}