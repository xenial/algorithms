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

void solve() {
    
}

int main() {
    set_io("");

    int n, m; cin >> n >> m;
    vector<int> a, b, c;
    while (m--) {
        int x, y, z; cin >> x >> y >> z;
        a.pb(x); b.pb(y); c.pb(z);
    }
}