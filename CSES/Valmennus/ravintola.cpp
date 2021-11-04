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

    int n; cin >> n;
    vector<pair<int,int>> times(n);
    for (int i = 0; i < n; i++) cin >> times[i].fi >> times[i].se;

    sort(all(times));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        
    }
}