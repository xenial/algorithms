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

int n;
typedef pair<ll,ll> Friend;
vector<Friend> friends;

bool valid(double t) {
    double l = INT_MAX, r = INT_MIN;
    for (int i = 0; i < friends.sz(); i++) {
        Friend f = friends[i];
        l = min(l, f.fi + t * f.se);
        r = max(r, f.fi - t * f.se);
    }
    return l >= r;
}

int main() {
    set_io("");
    
    cin >> n;
    friends.rsz(n);
    for (int i = 0; i < n; i++) cin >> friends[i].fi;
    for (int i = 0; i < n; i++) cin >> friends[i].se;
    sort(all(friends));

    // Binary search the minimum time for worst pair to meet
    double l = 0, r = 2e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (valid(m)) r = m;
        else l = m;
    }
    cout << setprecision(10) << r;
}