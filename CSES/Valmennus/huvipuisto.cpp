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

    int n, x; cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    sort(all(weights));

    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (weights[l] + weights[r] <= x) {
            ans++;
            l++;
            r--;
        } else {
            ans++;
            r--;
        }
    }
    if (l == r) if (l <= x) ans++;
    cout << ans;
}