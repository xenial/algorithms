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

typedef pair<ll,ll> point;
point start, dest;
vector<point> wind_prefix;

bool possible(ll t) {
    ll period = (t - 1) / wind_prefix.sz();
    point ostart = {start.fi + (period * wind_prefix[wind_prefix.sz() - 1].fi + wind_prefix[(t-1)%wind_prefix.sz()].fi), start.se + (period * wind_prefix[wind_prefix.sz() - 1].se + wind_prefix[(t-1)%wind_prefix.sz()].se)};
    point diff = {abs(ostart.fi - dest.fi), abs(ostart.se - dest.se)};
    return diff.fi + diff.se <= t;
}

point get_offset(char c) {
    point offset;
    switch (c) {
        case 'U': offset = {0, 1}; break;
        case 'D': offset = {0, -1}; break;
        case 'L': offset = {-1, 0}; break;
        case 'R': offset = {1, 0}; break;
    }
    return offset;
}

int main() {
    set_io("");

    cin >> start.fi >> start.se;
    cin >> dest.fi >> dest.se;
    int n; cin >> n;
    string wind; cin >> wind;
    wind_prefix.resize(wind.sz()); wind_prefix[0] = get_offset(wind[0]);
    for (int i = 1; i < wind.sz(); i++) {
        point offset = get_offset(wind[i]);
        point prev = wind_prefix[i-1];
        wind_prefix[i] = {prev.fi + offset.fi, prev.se + offset.se};
    }

    ll l = 0, r = 1e18;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (possible(m)) r = m;
        else l = m;
    }
    cout << (r == 1e18 ? -1 : r);
}