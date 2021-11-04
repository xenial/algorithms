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

    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    ll total = accumulate(all(weights), 0LL), ans = LONG_LONG_MAX;
    
    for (int i = 0; i < (1 << n); i++) {
        ll s = 0;
        for (int j = 0; j < n; j++) if (i & (1 << j)) s += weights[j];
        ans = min(ans, abs(s - (total - s)));
    }

    cout << ans;
}