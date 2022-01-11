#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

vector<ll> pf;

ll solve(int n) {
    ll minsum = pf[0], maxsum = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        maxsum = max(maxsum, pf[i] - minsum);
        minsum = min(minsum, (ll)pf[i]);
    }
    return maxsum;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;
    pf = vector<ll>(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pf[i];
        pf[i] += pf[i - 1];
    }
    cout << solve(n);
}