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

    vector<int> coins(n);
    for (auto &c : coins) cin >> c;
    sort(all(coins));

    ll res = 1;
    for (auto c : coins) {
        if (res < c) break;
        res += c;
    }
    cout << res << endl;
}
