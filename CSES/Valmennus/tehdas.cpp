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

int n, m;
vector<int> speeds;

bool possible(ll t) {
    ll prod = 0;
    for (auto speed : speeds) {
        prod += t / speed;
        if (prod >= m) return true;
    }
    return false;
}

int main() {
    set_io("");

    cin >> n >> m;

    speeds.rsz(n);
    for (int i = 0; i < n; i++) cin >> speeds[i];

    ll l = 0, r = LONG_LONG_MAX;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (possible(m)) r = m;
        else l = m;
    }
    cout << r;
}