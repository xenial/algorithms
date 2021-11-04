#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> a) {
    ll r = 0;
    for (int i = 1; i < a.size(); i++) {
        r = max(r, a[i - 1] * a[i]);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t, n;

    cin >> t;
    while (t--) {
        vector<ll> a;
        cin >> n;
        while (n--) {
            ll v;
            cin >> v;
            a.push_back(v);
        }
        cout << solve(a) << endl;
    }
}