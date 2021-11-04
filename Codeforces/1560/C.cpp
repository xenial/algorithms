#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll n) {
    if (n == 1)
        return vector<ll> {1, 1};

    for (ll i = 2; i < 1000000001; i++) {
        ll prev = (i - 1) * (i - 1);
        ll cur = i * i;
        if (prev < n && n <= cur) {
            ll c = cur - (i - 1);
            ll fd = cur - (i - 1) * 2;

            if (n == c)
                return vector<ll> {i, i};
            else if (n < c)
                return vector<ll> {1 + abs(n - fd), i};
            else
                return vector<ll> {i, 1 + abs(cur - n)};
        }
    }

    return vector<ll> {-1, -1};
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ll t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> s = solve(n);
        cout << s.at(0) << " " << s.at(1) << endl;
    }
}