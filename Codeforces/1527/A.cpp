#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    ll b;
    for (int i = 0; i < 32; i++) {
        if (n == 1) {
            b = i;
            break;
        }
        n = n >> 1;
    }    
    ll xd = (ll)pow(2, b) - 1;
    return xd;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ll t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}