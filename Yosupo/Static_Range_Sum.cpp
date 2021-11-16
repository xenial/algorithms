#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
ll p[500001];

ll solve(int l, int r) {
    return p[r] - p[l];
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << solve(l, r) << endl;
    }
}