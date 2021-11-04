#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b, ll c) {
    ll h = abs(a - b);

    if (h * 2 < a || h * 2 < b || h * 2 < c)
        return -1;

    ll ans = h + c;
    if (ans > h * 2)
        return ans - h * 2;
    else
        return ans;

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ll t, a, b, c;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
}