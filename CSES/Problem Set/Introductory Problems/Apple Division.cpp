#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<ll> a) {
    ll bdiff = LLONG_MAX;
    
    for (int i = 0; i < (1 << a.size()); i++) {
        vector<ll> sset, rset;
        for (int j = 0; j < a.size(); j++) {
            if (i & (1 << j)) sset.push_back(a[j]);
        }
        rset = a;

        for (auto n : sset) {
            rset.erase(find(rset.begin(), rset.end(), n));
        }

        ll ssum, rsum, diff;
        ssum = accumulate(sset.begin(), sset.end(), 0LL);
        rsum = accumulate(rset.begin(), rset.end(), 0LL);
        diff = abs(ssum - rsum);
        bdiff = min(diff, bdiff);
    }

    return bdiff;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    ll t, n;
    vector<ll> a;
    cin >> t;
    while (t--) {
        cin >> n;
        a.push_back(n);
    }
    cout << solve(a);
}