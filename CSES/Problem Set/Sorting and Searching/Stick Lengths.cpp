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

int main() {
	set_io("");

    int n; cin >> n;
    vector<ll> sticks(n);

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (auto &s : sticks) cin >> s;
    sort(all(sticks));

    ll med;
    if (n % 2) med = (sticks[n / 2] + sticks[n / 2 + 1]) / 2;
    else med = sticks[n / 2];

    ll ans = 0;
    for (auto s : sticks) ans += abs(s - med);
    cout << ans << endl;
}
